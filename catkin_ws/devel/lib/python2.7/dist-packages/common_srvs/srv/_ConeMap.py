# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from common_srvs/ConeMapRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class ConeMapRequest(genpy.Message):
  _md5sum = "d41d8cd98f00b204e9800998ecf8427e"
  _type = "common_srvs/ConeMapRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """"""
  __slots__ = []
  _slot_types = []

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ConeMapRequest, self).__init__(*args, **kwds)

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      pass
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      pass
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from common_srvs/ConeMapResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg
import common_msgs.msg

class ConeMapResponse(genpy.Message):
  _md5sum = "b7e5900e2ea08a404fe38a8b59685279"
  _type = "common_srvs/ConeMapResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """common_msgs/Cone[] blue_cones
common_msgs/Cone[] yellow_cones
common_msgs/Cone[] orange_cones


================================================================================
MSG: common_msgs/Cone
uint8 BLUE=0
uint8 YELLOW=1
uint8 ORANGE=2

geometry_msgs/Point position
uint8 color

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
"""
  __slots__ = ['blue_cones','yellow_cones','orange_cones']
  _slot_types = ['common_msgs/Cone[]','common_msgs/Cone[]','common_msgs/Cone[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       blue_cones,yellow_cones,orange_cones

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ConeMapResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.blue_cones is None:
        self.blue_cones = []
      if self.yellow_cones is None:
        self.yellow_cones = []
      if self.orange_cones is None:
        self.orange_cones = []
    else:
      self.blue_cones = []
      self.yellow_cones = []
      self.orange_cones = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.blue_cones)
      buff.write(_struct_I.pack(length))
      for val1 in self.blue_cones:
        _v1 = val1.position
        _x = _v1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        buff.write(_get_struct_B().pack(val1.color))
      length = len(self.yellow_cones)
      buff.write(_struct_I.pack(length))
      for val1 in self.yellow_cones:
        _v2 = val1.position
        _x = _v2
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        buff.write(_get_struct_B().pack(val1.color))
      length = len(self.orange_cones)
      buff.write(_struct_I.pack(length))
      for val1 in self.orange_cones:
        _v3 = val1.position
        _x = _v3
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        buff.write(_get_struct_B().pack(val1.color))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.blue_cones is None:
        self.blue_cones = None
      if self.yellow_cones is None:
        self.yellow_cones = None
      if self.orange_cones is None:
        self.orange_cones = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.blue_cones = []
      for i in range(0, length):
        val1 = common_msgs.msg.Cone()
        _v4 = val1.position
        _x = _v4
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        start = end
        end += 1
        (val1.color,) = _get_struct_B().unpack(str[start:end])
        self.blue_cones.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.yellow_cones = []
      for i in range(0, length):
        val1 = common_msgs.msg.Cone()
        _v5 = val1.position
        _x = _v5
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        start = end
        end += 1
        (val1.color,) = _get_struct_B().unpack(str[start:end])
        self.yellow_cones.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.orange_cones = []
      for i in range(0, length):
        val1 = common_msgs.msg.Cone()
        _v6 = val1.position
        _x = _v6
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        start = end
        end += 1
        (val1.color,) = _get_struct_B().unpack(str[start:end])
        self.orange_cones.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.blue_cones)
      buff.write(_struct_I.pack(length))
      for val1 in self.blue_cones:
        _v7 = val1.position
        _x = _v7
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        buff.write(_get_struct_B().pack(val1.color))
      length = len(self.yellow_cones)
      buff.write(_struct_I.pack(length))
      for val1 in self.yellow_cones:
        _v8 = val1.position
        _x = _v8
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        buff.write(_get_struct_B().pack(val1.color))
      length = len(self.orange_cones)
      buff.write(_struct_I.pack(length))
      for val1 in self.orange_cones:
        _v9 = val1.position
        _x = _v9
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        buff.write(_get_struct_B().pack(val1.color))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.blue_cones is None:
        self.blue_cones = None
      if self.yellow_cones is None:
        self.yellow_cones = None
      if self.orange_cones is None:
        self.orange_cones = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.blue_cones = []
      for i in range(0, length):
        val1 = common_msgs.msg.Cone()
        _v10 = val1.position
        _x = _v10
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        start = end
        end += 1
        (val1.color,) = _get_struct_B().unpack(str[start:end])
        self.blue_cones.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.yellow_cones = []
      for i in range(0, length):
        val1 = common_msgs.msg.Cone()
        _v11 = val1.position
        _x = _v11
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        start = end
        end += 1
        (val1.color,) = _get_struct_B().unpack(str[start:end])
        self.yellow_cones.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.orange_cones = []
      for i in range(0, length):
        val1 = common_msgs.msg.Cone()
        _v12 = val1.position
        _x = _v12
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        start = end
        end += 1
        (val1.color,) = _get_struct_B().unpack(str[start:end])
        self.orange_cones.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
class ConeMap(object):
  _type          = 'common_srvs/ConeMap'
  _md5sum = 'b7e5900e2ea08a404fe38a8b59685279'
  _request_class  = ConeMapRequest
  _response_class = ConeMapResponse
