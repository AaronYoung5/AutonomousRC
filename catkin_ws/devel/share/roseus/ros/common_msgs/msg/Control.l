;; Auto-generated. Do not edit!


(when (boundp 'common_msgs::Control)
  (if (not (find-package "COMMON_MSGS"))
    (make-package "COMMON_MSGS"))
  (shadow 'Control (find-package "COMMON_MSGS")))
(unless (find-package "COMMON_MSGS::CONTROL")
  (make-package "COMMON_MSGS::CONTROL"))

(in-package "ROS")
;;//! \htmlinclude Control.msg.html


(defclass common_msgs::Control
  :super ros::object
  :slots (_throttle _braking _steering ))

(defmethod common_msgs::Control
  (:init
   (&key
    ((:throttle __throttle) 0.0)
    ((:braking __braking) 0.0)
    ((:steering __steering) 0.0)
    )
   (send-super :init)
   (setq _throttle (float __throttle))
   (setq _braking (float __braking))
   (setq _steering (float __steering))
   self)
  (:throttle
   (&optional __throttle)
   (if __throttle (setq _throttle __throttle)) _throttle)
  (:braking
   (&optional __braking)
   (if __braking (setq _braking __braking)) _braking)
  (:steering
   (&optional __steering)
   (if __steering (setq _steering __steering)) _steering)
  (:serialization-length
   ()
   (+
    ;; float32 _throttle
    4
    ;; float32 _braking
    4
    ;; float32 _steering
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _throttle
       (sys::poke _throttle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _braking
       (sys::poke _braking (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _steering
       (sys::poke _steering (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _throttle
     (setq _throttle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _braking
     (setq _braking (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _steering
     (setq _steering (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get common_msgs::Control :md5sum-) "6809fdf3d0c63bf8235c6fb5bb38a2d5")
(setf (get common_msgs::Control :datatype-) "common_msgs/Control")
(setf (get common_msgs::Control :definition-)
      "float32 throttle
float32 braking
float32 steering

")



(provide :common_msgs/Control "6809fdf3d0c63bf8235c6fb5bb38a2d5")


