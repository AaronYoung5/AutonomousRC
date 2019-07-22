; Auto-generated. Do not edit!


(cl:in-package common_srvs-srv)


;//! \htmlinclude Path-request.msg.html

(cl:defclass <Path-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Path-request (<Path-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Path-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Path-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_srvs-srv:<Path-request> is deprecated: use common_srvs-srv:Path-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Path-request>) ostream)
  "Serializes a message object of type '<Path-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Path-request>) istream)
  "Deserializes a message object of type '<Path-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Path-request>)))
  "Returns string type for a service object of type '<Path-request>"
  "common_srvs/PathRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Path-request)))
  "Returns string type for a service object of type 'Path-request"
  "common_srvs/PathRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Path-request>)))
  "Returns md5sum for a message object of type '<Path-request>"
  "3fb3f9dacc279b964c4c8341122c34df")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Path-request)))
  "Returns md5sum for a message object of type 'Path-request"
  "3fb3f9dacc279b964c4c8341122c34df")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Path-request>)))
  "Returns full string definition for message of type '<Path-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Path-request)))
  "Returns full string definition for message of type 'Path-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Path-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Path-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Path-request
))
;//! \htmlinclude Path-response.msg.html

(cl:defclass <Path-response> (roslisp-msg-protocol:ros-message)
  ((points
    :reader points
    :initarg :points
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point))))
)

(cl:defclass Path-response (<Path-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Path-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Path-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_srvs-srv:<Path-response> is deprecated: use common_srvs-srv:Path-response instead.")))

(cl:ensure-generic-function 'points-val :lambda-list '(m))
(cl:defmethod points-val ((m <Path-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_srvs-srv:points-val is deprecated.  Use common_srvs-srv:points instead.")
  (points m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Path-response>) ostream)
  "Serializes a message object of type '<Path-response>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'points))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'points))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Path-response>) istream)
  "Deserializes a message object of type '<Path-response>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'points) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'points)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Path-response>)))
  "Returns string type for a service object of type '<Path-response>"
  "common_srvs/PathResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Path-response)))
  "Returns string type for a service object of type 'Path-response"
  "common_srvs/PathResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Path-response>)))
  "Returns md5sum for a message object of type '<Path-response>"
  "3fb3f9dacc279b964c4c8341122c34df")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Path-response)))
  "Returns md5sum for a message object of type 'Path-response"
  "3fb3f9dacc279b964c4c8341122c34df")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Path-response>)))
  "Returns full string definition for message of type '<Path-response>"
  (cl:format cl:nil "geometry_msgs/Point[] points~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Path-response)))
  "Returns full string definition for message of type 'Path-response"
  (cl:format cl:nil "geometry_msgs/Point[] points~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Path-response>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'points) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Path-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Path-response
    (cl:cons ':points (points msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Path)))
  'Path-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Path)))
  'Path-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Path)))
  "Returns string type for a service object of type '<Path>"
  "common_srvs/Path")