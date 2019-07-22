// Auto-generated. Do not edit!

// (in-package common_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class PIDDebug {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.point_following = null;
    }
    else {
      if (initObj.hasOwnProperty('point_following')) {
        this.point_following = initObj.point_following
      }
      else {
        this.point_following = new geometry_msgs.msg.Point();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PIDDebug
    // Serialize message field [point_following]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.point_following, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PIDDebug
    let len;
    let data = new PIDDebug(null);
    // Deserialize message field [point_following]
    data.point_following = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'common_msgs/PIDDebug';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'acbcde480248f453332a6d1026e2caff';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/Point point_following
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PIDDebug(null);
    if (msg.point_following !== undefined) {
      resolved.point_following = geometry_msgs.msg.Point.Resolve(msg.point_following)
    }
    else {
      resolved.point_following = new geometry_msgs.msg.Point()
    }

    return resolved;
    }
};

module.exports = PIDDebug;
