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
PointCloudClusterer::Cluster(pcl::PCLPointCloud2 &msg) {
  // Convert the pcl/PCLPointCloud2 data to pcl/PointCloud
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(
      new pcl::PointCloud<pcl::PointXYZRGB>),
      cloud_f(new pcl::PointCloud<pcl::PointXYZRGB>);
  pcl::fromPCLPointCloud2(msg, *cloud);

  pcl::console::TicToc tt;
  std::cerr << "Starting...\n", tt.tic();

  // Create the filtering object: downsample the dataset using a leaf size of
  // 1cm
  pcl::VoxelGrid<pcl::PointXYZRGB> vg;
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(
      new pcl::PointCloud<pcl::PointXYZRGB>);
  vg.setInputCloud(cloud);
  vg.setLeafSize(0.01f, 0.01f, 0.01f);
  vg.filter(*cloud_filtered);
  // std::cout << "PointCloud after filtering has: "
            // << cloud_filtered->points.size() << " data points."
            // << std::endl; //*

  pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_plane(
      new pcl::PointCloud<pcl::PointXYZRGB>());

  int i = 0, nr_points = (int)cloud_filtered->points.size();
  while (cloud_filtered->points.size() > 0.3 * nr_points) {
    if (inliers->indices.size() == 0) {
      break;
    }

    // Extract the planar inliers from the input cloud
    pcl::ExtractIndices<pcl::PointXYZRGB> extract;
    extract.setInputCloud(cloud_filtered);
    extract.setIndices(inliers);
    extract.setNegative(false);

    // Get the points associated with the cone
    extract.filter(*cloud_plane);

    // Remove the cone inliers, extract the rest
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
  ec.setClusterTolerance(.05); // 2cm
  ec.setMinClusterSize(40);
  ec.setMaxClusterSize(10000);
  ec.setSearchMethod(tree);
  ec.setInputCloud(cloud_filtered);
  ec.extract(cluster_indices);

  // std::cout << "Length of Point Indices :: " << cluster_indices.size()
  // << std::endl;

  int j = 0;
  map_.red_cones.resize(0);
  for (std::vector<pcl::PointIndices>::const_iterator it =
           cluster_indices.begin();
       it != cluster_indices.end(); ++it) {
    // Find centroid
    Eigen::Vector4f centroid;
    pcl::compute3DCentroid(*cloud_cluster, centroid);
    // cout << centroid[0] << " " << centroid[1] << " " << centroid[2] << " "
         // << centroid[3] << " \n";

    perception_msgs::ConeXY cone;
    cone.pos.x = centroid[0];
    cone.pos.y = centroid[1];
    cone.pos.z = centroid[2];
    map_.red_cones.push_back(cone);
  }

  std::cerr << ">> Done: " << tt.toc() << " ms, " << cluster_indices.size()
            << " clusters found\n";

  return map_;
}
