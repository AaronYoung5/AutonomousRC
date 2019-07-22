;; Auto-generated. Do not edit!


(when (boundp 'common_msgs::PIDDebug)
  (if (not (find-package "COMMON_MSGS"))
    (make-package "COMMON_MSGS"))
  (shadow 'PIDDebug (find-package "COMMON_MSGS")))
(unless (find-package "COMMON_MSGS::PIDDEBUG")
  (make-package "COMMON_MSGS::PIDDEBUG"))

(in-package "ROS")
;;//! \htmlinclude PIDDebug.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass common_msgs::PIDDebug
  :super ros::object
  :slots (_point_following ))

(defmethod common_msgs::PIDDebug
  (:init
   (&key
    ((:point_following __point_following) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _point_following __point_following)
   self)
  (:point_following
   (&rest __point_following)
   (if (keywordp (car __point_following))
       (send* _point_following __point_following)
     (progn
       (if __point_following (setq _point_following (car __point_following)))
       _point_following)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _point_following
    (send _point_following :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _point_following
       (send _point_following :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _point_following
     (send _point_following :deserialize buf ptr-) (incf ptr- (send _point_following :serialization-length))
   ;;
   self)
  )

(setf (get common_msgs::PIDDebug :md5sum-) "acbcde480248f453332a6d1026e2caff")
(setf (get common_msgs::PIDDebug :datatype-) "common_msgs/PIDDebug")
(setf (get common_msgs::PIDDebug :definition-)
      "geometry_msgs/Point point_following

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :common_msgs/PIDDebug "acbcde480248f453332a6d1026e2caff")


