;; Auto-generated. Do not edit!


(when (boundp 'common_srvs::Path)
  (if (not (find-package "COMMON_SRVS"))
    (make-package "COMMON_SRVS"))
  (shadow 'Path (find-package "COMMON_SRVS")))
(unless (find-package "COMMON_SRVS::PATH")
  (make-package "COMMON_SRVS::PATH"))
(unless (find-package "COMMON_SRVS::PATHREQUEST")
  (make-package "COMMON_SRVS::PATHREQUEST"))
(unless (find-package "COMMON_SRVS::PATHRESPONSE")
  (make-package "COMMON_SRVS::PATHRESPONSE"))

(in-package "ROS")



(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass common_srvs::PathRequest
  :super ros::object
  :slots ())

(defmethod common_srvs::PathRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass common_srvs::PathResponse
  :super ros::object
  :slots (_points ))

(defmethod common_srvs::PathResponse
  (:init
   (&key
    ((:points __points) (let (r) (dotimes (i 0) (push (instance geometry_msgs::Point :init) r)) r))
    )
   (send-super :init)
   (setq _points __points)
   self)
  (:points
   (&rest __points)
   (if (keywordp (car __points))
       (send* _points __points)
     (progn
       (if __points (setq _points (car __points)))
       _points)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point[] _points
    (apply #'+ (send-all _points :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point[] _points
     (write-long (length _points) s)
     (dolist (elem _points)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point[] _points
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _points (let (r) (dotimes (i n) (push (instance geometry_msgs::Point :init) r)) r))
     (dolist (elem- _points)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(defclass common_srvs::Path
  :super ros::object
  :slots ())

(setf (get common_srvs::Path :md5sum-) "3fb3f9dacc279b964c4c8341122c34df")
(setf (get common_srvs::Path :datatype-) "common_srvs/Path")
(setf (get common_srvs::Path :request) common_srvs::PathRequest)
(setf (get common_srvs::Path :response) common_srvs::PathResponse)

(defmethod common_srvs::PathRequest
  (:response () (instance common_srvs::PathResponse :init)))

(setf (get common_srvs::PathRequest :md5sum-) "3fb3f9dacc279b964c4c8341122c34df")
(setf (get common_srvs::PathRequest :datatype-) "common_srvs/PathRequest")
(setf (get common_srvs::PathRequest :definition-)
      "---
geometry_msgs/Point[] points


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
")

(setf (get common_srvs::PathResponse :md5sum-) "3fb3f9dacc279b964c4c8341122c34df")
(setf (get common_srvs::PathResponse :datatype-) "common_srvs/PathResponse")
(setf (get common_srvs::PathResponse :definition-)
      "---
geometry_msgs/Point[] points


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
")



(provide :common_srvs/Path "3fb3f9dacc279b964c4c8341122c34df")


