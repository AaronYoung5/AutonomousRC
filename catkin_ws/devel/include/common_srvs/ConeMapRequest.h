// Generated by gencpp from file common_srvs/ConeMapRequest.msg
// DO NOT EDIT!


#ifndef COMMON_SRVS_MESSAGE_CONEMAPREQUEST_H
#define COMMON_SRVS_MESSAGE_CONEMAPREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace common_srvs
{
template <class ContainerAllocator>
struct ConeMapRequest_
{
  typedef ConeMapRequest_<ContainerAllocator> Type;

  ConeMapRequest_()
    {
    }
  ConeMapRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::common_srvs::ConeMapRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::common_srvs::ConeMapRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ConeMapRequest_

typedef ::common_srvs::ConeMapRequest_<std::allocator<void> > ConeMapRequest;

typedef boost::shared_ptr< ::common_srvs::ConeMapRequest > ConeMapRequestPtr;
typedef boost::shared_ptr< ::common_srvs::ConeMapRequest const> ConeMapRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::common_srvs::ConeMapRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::common_srvs::ConeMapRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace common_srvs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'common_msgs': ['/home/aaron/AutonomousRC/catkin_ws/src/common/common_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::common_srvs::ConeMapRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::common_srvs::ConeMapRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common_srvs::ConeMapRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common_srvs::ConeMapRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common_srvs::ConeMapRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common_srvs::ConeMapRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::common_srvs::ConeMapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::common_srvs::ConeMapRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::common_srvs::ConeMapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "common_srvs/ConeMapRequest";
  }

  static const char* value(const ::common_srvs::ConeMapRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::common_srvs::ConeMapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::common_srvs::ConeMapRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::common_srvs::ConeMapRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ConeMapRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::common_srvs::ConeMapRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::common_srvs::ConeMapRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // COMMON_SRVS_MESSAGE_CONEMAPREQUEST_H
