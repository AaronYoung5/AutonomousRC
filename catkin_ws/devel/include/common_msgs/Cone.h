// Generated by gencpp from file common_msgs/Cone.msg
// DO NOT EDIT!


#ifndef COMMON_MSGS_MESSAGE_CONE_H
#define COMMON_MSGS_MESSAGE_CONE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>

namespace common_msgs
{
template <class ContainerAllocator>
struct Cone_
{
  typedef Cone_<ContainerAllocator> Type;

  Cone_()
    : position()
    , color(0)  {
    }
  Cone_(const ContainerAllocator& _alloc)
    : position(_alloc)
    , color(0)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _position_type;
  _position_type position;

   typedef uint8_t _color_type;
  _color_type color;



  enum {
    BLUE = 0u,
    YELLOW = 1u,
    ORANGE = 2u,
  };


  typedef boost::shared_ptr< ::common_msgs::Cone_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::common_msgs::Cone_<ContainerAllocator> const> ConstPtr;

}; // struct Cone_

typedef ::common_msgs::Cone_<std::allocator<void> > Cone;

typedef boost::shared_ptr< ::common_msgs::Cone > ConePtr;
typedef boost::shared_ptr< ::common_msgs::Cone const> ConeConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::common_msgs::Cone_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::common_msgs::Cone_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace common_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'common_msgs': ['/home/aaron/AutonomousRC/catkin_ws/src/common/common_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::common_msgs::Cone_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::common_msgs::Cone_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common_msgs::Cone_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::common_msgs::Cone_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common_msgs::Cone_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::common_msgs::Cone_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::common_msgs::Cone_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b30308676f596f91d4defb29138731c2";
  }

  static const char* value(const ::common_msgs::Cone_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb30308676f596f91ULL;
  static const uint64_t static_value2 = 0xd4defb29138731c2ULL;
};

template<class ContainerAllocator>
struct DataType< ::common_msgs::Cone_<ContainerAllocator> >
{
  static const char* value()
  {
    return "common_msgs/Cone";
  }

  static const char* value(const ::common_msgs::Cone_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::common_msgs::Cone_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 BLUE=0\n"
"uint8 YELLOW=1\n"
"uint8 ORANGE=2\n"
"\n"
"geometry_msgs/Point position\n"
"uint8 color\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::common_msgs::Cone_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::common_msgs::Cone_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.position);
      stream.next(m.color);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Cone_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::common_msgs::Cone_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::common_msgs::Cone_<ContainerAllocator>& v)
  {
    s << indent << "position: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.position);
    s << indent << "color: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.color);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COMMON_MSGS_MESSAGE_CONE_H
