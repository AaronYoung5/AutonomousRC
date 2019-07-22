; Auto-generated. Do not edit!


(cl:in-package common_msgs-msg)


;//! \htmlinclude PIDDebug.msg.html

(cl:defclass <PIDDebug> (roslisp-msg-protocol:ros-message)
  ((point_following
    :reader point_following
    :initarg :point_following
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass PIDDebug (<PIDDebug>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PIDDebug>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PIDDebug)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common_msgs-msg:<PIDDebug> is deprecated: use common_msgs-msg:PIDDebug instead.")))

(cl:ensure-generic-function 'point_following-val :lambda-list '(m))
(cl:defmethod point_following-val ((m <PIDDebug>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common_msgs-msg:point_following-val is deprecated.  Use common_msgs-msg:point_following instead.")
  (point_following m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PIDDebug>) ostream)
  "Serializes a message object of type '<PIDDebug>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'point_following) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PIDDebug>) istream)
  "Deserializes a message object of type '<PIDDebug>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'point_following) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PIDDebug>)))
  "Returns string type for a message object of type '<PIDDebug>"
  "common_msgs/PIDDebug")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PIDDebug)))
  "Returns string type for a message object of type 'PIDDebug"
  "common_msgs/PIDDebug")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PIDDebug>)))
  "Returns md5sum for a message object of type '<PIDDebug>"
  "acbcde480248f453332a6d1026e2caff")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PIDDebug)))
  "Returns md5sum for a message object of type 'PIDDebug"
  "acbcde480248f453332a6d1026e2caff")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PIDDebug>)))
  "Returns full string definition for message of type '<PIDDebug>"
  (cl:format cl:nil "geometry_msgs/Point point_following~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PIDDebug)))
  "Returns full string definition for message of type 'PIDDebug"
  (cl:format cl:nil "geometry_msgs/Point point_following~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PIDDebug>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'point_following))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PIDDebug>))
  "Converts a ROS message object to a list"
  (cl:list 'PIDDebug
    (cl:cons ':point_following (point_following msg))
))
