; Auto-generated. Do not edit!


(cl:in-package common_srvs-srv)


;//! \htmlinclude ConeMap-request.msg.html

(cl:defclass <ConeMap-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ConeMap-request (<ConeMap-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ConeMap-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ConeMap-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_srvs-srv:<ConeMap-request> is deprecated: use common_srvs-srv:ConeMap-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ConeMap-request>) ostream)
  "Serializes a message object of type '<ConeMap-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ConeMap-request>) istream)
  "Deserializes a message object of type '<ConeMap-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ConeMap-request>)))
  "Returns string type for a service object of type '<ConeMap-request>"
  "common_srvs/ConeMapRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ConeMap-request)))
  "Returns string type for a service object of type 'ConeMap-request"
  "common_srvs/ConeMapRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ConeMap-request>)))
  "Returns md5sum for a message object of type '<ConeMap-request>"
  "b7e5900e2ea08a404fe38a8b59685279")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ConeMap-request)))
  "Returns md5sum for a message object of type 'ConeMap-request"
  "b7e5900e2ea08a404fe38a8b59685279")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ConeMap-request>)))
  "Returns full string definition for message of type '<ConeMap-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ConeMap-request)))
  "Returns full string definition for message of type 'ConeMap-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ConeMap-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ConeMap-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ConeMap-request
))
;//! \htmlinclude ConeMap-response.msg.html

(cl:defclass <ConeMap-response> (roslisp-msg-protocol:ros-message)
  ((blue_cones
    :reader blue_cones
    :initarg :blue_cones
    :type (cl:vector common_msgs-msg:Cone)
   :initform (cl:make-array 0 :element-type 'common_msgs-msg:Cone :initial-element (cl:make-instance 'common_msgs-msg:Cone)))
   (yellow_cones
    :reader yellow_cones
    :initarg :yellow_cones
    :type (cl:vector common_msgs-msg:Cone)
   :initform (cl:make-array 0 :element-type 'common_msgs-msg:Cone :initial-element (cl:make-instance 'common_msgs-msg:Cone)))
   (orange_cones
    :reader orange_cones
    :initarg :orange_cones
    :type (cl:vector common_msgs-msg:Cone)
   :initform (cl:make-array 0 :element-type 'common_msgs-msg:Cone :initial-element (cl:make-instance 'common_msgs-msg:Cone))))
)

(cl:defclass ConeMap-response (<ConeMap-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ConeMap-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ConeMap-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_srvs-srv:<ConeMap-response> is deprecated: use common_srvs-srv:ConeMap-response instead.")))

(cl:ensure-generic-function 'blue_cones-val :lambda-list '(m))
(cl:defmethod blue_cones-val ((m <ConeMap-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_srvs-srv:blue_cones-val is deprecated.  Use common_srvs-srv:blue_cones instead.")
  (blue_cones m))

(cl:ensure-generic-function 'yellow_cones-val :lambda-list '(m))
(cl:defmethod yellow_cones-val ((m <ConeMap-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_srvs-srv:yellow_cones-val is deprecated.  Use common_srvs-srv:yellow_cones instead.")
  (yellow_cones m))

(cl:ensure-generic-function 'orange_cones-val :lambda-list '(m))
(cl:defmethod orange_cones-val ((m <ConeMap-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_srvs-srv:orange_cones-val is deprecated.  Use common_srvs-srv:orange_cones instead.")
  (orange_cones m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ConeMap-response>) ostream)
  "Serializes a message object of type '<ConeMap-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'blue_cones))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'blue_cones))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'yellow_cones))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'yellow_cones))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'orange_cones))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'orange_cones))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ConeMap-response>) istream)
  "Deserializes a message object of type '<ConeMap-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'blue_cones) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'blue_cones)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'common_msgs-msg:Cone))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'yellow_cones) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'yellow_cones)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'common_msgs-msg:Cone))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'orange_cones) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'orange_cones)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'common_msgs-msg:Cone))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ConeMap-response>)))
  "Returns string type for a service object of type '<ConeMap-response>"
  "common_srvs/ConeMapResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ConeMap-response)))
  "Returns string type for a service object of type 'ConeMap-response"
  "common_srvs/ConeMapResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ConeMap-response>)))
  "Returns md5sum for a message object of type '<ConeMap-response>"
  "b7e5900e2ea08a404fe38a8b59685279")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ConeMap-response)))
  "Returns md5sum for a message object of type 'ConeMap-response"
  "b7e5900e2ea08a404fe38a8b59685279")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ConeMap-response>)))
  "Returns full string definition for message of type '<ConeMap-response>"
  (cl:format cl:nil "common_msgs/Cone[] blue_cones~%common_msgs/Cone[] yellow_cones~%common_msgs/Cone[] orange_cones~%~%~%================================================================================~%MSG: common_msgs/Cone~%uint8 BLUE=0~%uint8 YELLOW=1~%uint8 ORANGE=2~%~%geometry_msgs/Point position~%uint8 color~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ConeMap-response)))
  "Returns full string definition for message of type 'ConeMap-response"
  (cl:format cl:nil "common_msgs/Cone[] blue_cones~%common_msgs/Cone[] yellow_cones~%common_msgs/Cone[] orange_cones~%~%~%================================================================================~%MSG: common_msgs/Cone~%uint8 BLUE=0~%uint8 YELLOW=1~%uint8 ORANGE=2~%~%geometry_msgs/Point position~%uint8 color~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ConeMap-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'blue_cones) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'yellow_cones) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'orange_cones) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ConeMap-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ConeMap-response
    (cl:cons ':blue_cones (blue_cones msg))
    (cl:cons ':yellow_cones (yellow_cones msg))
    (cl:cons ':orange_cones (orange_cones msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ConeMap)))
  'ConeMap-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ConeMap)))
  'ConeMap-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ConeMap)))
  "Returns string type for a service object of type '<ConeMap>"
  "common_srvs/ConeMap")