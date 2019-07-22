// Auto-generated. Do not edit!

// (in-package common_srvs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

let common_msgs = _finder('common_msgs');

//-----------------------------------------------------------

class ConeMapRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ConeMapRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ConeMapRequest
    let len;
    let data = new ConeMapRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'common_srvs/ConeMapRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ConeMapRequest(null);
    return resolved;
    }
};

class ConeMapResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.blue_cones = null;
      this.yellow_cones = null;
      this.orange_cones = null;
    }
    else {
      if (initObj.hasOwnProperty('blue_cones')) {
        this.blue_cones = initObj.blue_cones
      }
      else {
        this.blue_cones = [];
      }
      if (initObj.hasOwnProperty('yellow_cones')) {
        this.yellow_cones = initObj.yellow_cones
      }
      else {
        this.yellow_cones = [];
      }
      if (initObj.hasOwnProperty('orange_cones')) {
        this.orange_cones = initObj.orange_cones
      }
      else {
        this.orange_cones = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ConeMapResponse
    // Serialize message field [blue_cones]
    // Serialize the length for message field [blue_cones]
    bufferOffset = _serializer.uint32(obj.blue_cones.length, buffer, bufferOffset);
    obj.blue_cones.forEach((val) => {
      bufferOffset = common_msgs.msg.Cone.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [yellow_cones]
    // Serialize the length for message field [yellow_cones]
    bufferOffset = _serializer.uint32(obj.yellow_cones.length, buffer, bufferOffset);
    obj.yellow_cones.forEach((val) => {
      bufferOffset = common_msgs.msg.Cone.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [orange_cones]
    // Serialize the length for message field [orange_cones]
    bufferOffset = _serializer.uint32(obj.orange_cones.length, buffer, bufferOffset);
    obj.orange_cones.forEach((val) => {
      bufferOffset = common_msgs.msg.Cone.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ConeMapResponse
    let len;
    let data = new ConeMapResponse(null);
    // Deserialize message field [blue_cones]
    // Deserialize array length for message field [blue_cones]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.blue_cones = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.blue_cones[i] = common_msgs.msg.Cone.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [yellow_cones]
    // Deserialize array length for message field [yellow_cones]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.yellow_cones = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.yellow_cones[i] = common_msgs.msg.Cone.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [orange_cones]
    // Deserialize array length for message field [orange_cones]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.orange_cones = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.orange_cones[i] = common_msgs.msg.Cone.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 25 * object.blue_cones.length;
    length += 25 * object.yellow_cones.length;
    length += 25 * object.orange_cones.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a service object
    return 'common_srvs/ConeMapResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b7e5900e2ea08a404fe38a8b59685279';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    common_msgs/Cone[] blue_cones
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ConeMapResponse(null);
    if (msg.blue_cones !== undefined) {
      resolved.blue_cones = new Array(msg.blue_cones.length);
      for (let i = 0; i < resolved.blue_cones.length; ++i) {
        resolved.blue_cones[i] = common_msgs.msg.Cone.Resolve(msg.blue_cones[i]);
      }
    }
    else {
      resolved.blue_cones = []
    }

    if (msg.yellow_cones !== undefined) {
      resolved.yellow_cones = new Array(msg.yellow_cones.length);
      for (let i = 0; i < resolved.yellow_cones.length; ++i) {
        resolved.yellow_cones[i] = common_msgs.msg.Cone.Resolve(msg.yellow_cones[i]);
      }
    }
    else {
      resolved.yellow_cones = []
    }

    if (msg.orange_cones !== undefined) {
      resolved.orange_cones = new Array(msg.orange_cones.length);
      for (let i = 0; i < resolved.orange_cones.length; ++i) {
        resolved.orange_cones[i] = common_msgs.msg.Cone.Resolve(msg.orange_cones[i]);
      }
    }
    else {
      resolved.orange_cones = []
    }

    return resolved;
    }
};

module.exports = {
  Request: ConeMapRequest,
  Response: ConeMapResponse,
  md5sum() { return 'b7e5900e2ea08a404fe38a8b59685279'; },
  datatype() { return 'common_srvs/ConeMap'; }
};
