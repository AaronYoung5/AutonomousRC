#include "point_cloud_thresholder/clusterer.h"

#include <thread>

#include <pcl/ModelCoefficients.h>
#include <pcl/common/centroid.h>
#include <pcl/console/time.h>
#include <pcl/features/normal_3d.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/visualization/cloud_viewer.h>

PointCloudClusterer::PointCloudClusterer() {}

perception_msgs::ConeDepthMap &
PointCloudClusterer::Cluster(sensor_msgs::PointCloud2 &msg) {
  // Convert the sensor_msgs/PointCloud2 data to pcl/PointCloud
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;
  pcl::fromROSMsg(*input, cloud);

  pcl::console::TicToc tt;
  std::cerr << "Starting...\n", tt.tic();

  // Create the filtering object: downsample the dataset using a leaf size of
  // 1cm
  pcl::VoxelGrid<pcl::PointXYZRGB> vg;
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(
      new pcl::PointCloud<pcl::PointXYZRGB>);
  vg.setInputCloud(cloud);
  vg.setLeafSize(0.005f, 0.005f, 0.005f);
  vg.filter(*cloud_filtered);
  std::cout << "PointCloud after filtering has: "
            << cloud_filtered->points.size() << " data points."
            << std::endl; //*

  // Create the segmentation object for the planar model and set all the
  // parameters
  pcl::SACSegmentation<pcl::PointXYZRGB> seg;
  pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
  pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_plane(
      new pcl::PointCloud<pcl::PointXYZRGB>());
  pcl::PCDWriter writer;
  seg.setOptimizeCoefficients(true);
  seg.setModelType(pcl::SACMODEL_CONE);
  seg.setMethodType(pcl::SAC_RANSAC);
  seg.setMaxIterations(10);
  seg.setDistanceThreshold(0.02);

  int i = 0, nr_points = (int)cloud_filtered->points.size();
  while (cloud_filtered->points.size() > 0.3 * nr_points) {
    // Segment the largest planar component from the remaining cloud
    seg.setInputCloud(cloud_filtered);
    seg.segment(*inliers, *coefficients);
    if (inliers->indices.size() == 0) {
      std::cout << "Could not estimate a planar model for the given dataset."
                << std::endl;
      break;
    }

    // Extract the planar inliers from the input cloud
    pcl::ExtractIndices<pcl::PointXYZRGB> extract;
    extract.setInputCloud(cloud_filtered);
    extract.setIndices(inliers);
    extract.setNegative(false);

    // Get the points associated with the planar surface
    extract.filter(*cloud_plane);
    std::cout << "PointCloud representing the planar component: "
              << cloud_plane->points.size() << " data points." << std::endl;

    // Remove the planar inliers, extract the rest
    extract.setNegative(true);
    extract.filter(*cloud_f);
    *cloud_filtered = *cloud_f;
  }

  // Creating the KdTree object for the search method of the extraction
  pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(
      new pcl::search::KdTree<pcl::PointXYZRGB>);
  tree->setInputCloud(cloud_filtered);

  std::vector<pcl::PointIndices> cluster_indices;
  pcl::EuclideanClusterExtraction<pcl::PointXYZRGB> ec;
  ec.setClusterTolerance(.02); // 2cm
  ec.setMinClusterSize(100);
  ec.setMaxClusterSize(10000);
  ec.setSearchMethod(tree);
  ec.setInputCloud(cloud_filtered);
  ec.extract(cluster_indices);

  std::cout << "Length of Point Indices :: " << cluster_indices.size()
            << std::endl;

  int j = 0;
  for (std::vector<pcl::PointIndices>::const_iterator it =
           cluster_indices.begin();
       it != cluster_indices.end(); ++it) {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_cluster(
        new pcl::PointCloud<pcl::PointXYZRGB>);
    for (std::vector<int>::const_iterator pit = it->indices.begin();
         pit != it->indices.end(); ++pit) {
      cloud_filtered->points[*pit].r = 255;
      cloud_filtered->points[*pit].g = 0;
      cloud_filtered->points[*pit].b = 0;
      cloud_cluster->points.push_back(cloud_filtered->points[*pit]); //*
    }
    cloud_cluster->width = cloud_cluster->points.size();
    cloud_cluster->height = 1;
    cloud_cluster->is_dense = true;

    // Find centroid
    Eigen::Vector4f centroid;
    pcl::compute3DCentroid(*cloud_cluster, centroid);
    cout << centroid[0] << " " << centroid[1] << " " << centroid[2] << " "
         << centroid[3] << " \n";

    std::cout << "PointCloud representing the Cluster: "
              << cloud_cluster->points.size() << " data points." << std::endl;
    std::stringstream ss;
    ss << "cloud_cluster_" << j << ".pcd";
    writer.write<pcl::PointXYZRGB>(ss.str(), *cloud_cluster, false); //*
    j++;
  }
  std::cerr << ">> Done: " << tt.toc() << " ms, " << cluster_indices.size()
            << " clusters found\n";
}
