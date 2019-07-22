;; Auto-generated. Do not edit!


(when (boundp 'common_srvs::ConeMap)
  (if (not (find-package "COMMON_SRVS"))
    (make-package "COMMON_SRVS"))
  (shadow 'ConeMap (find-package "COMMON_SRVS")))
(unless (find-package "COMMON_SRVS::CONEMAP")
  (make-package "COMMON_SRVS::CONEMAP"))
(unless (find-package "COMMON_SRVS::CONEMAPREQUEST")
  (make-package "COMMON_SRVS::CONEMAPREQUEST"))
(unless (find-package "COMMON_SRVS::CONEMAPRESPONSE")
  (make-package "COMMON_SRVS::CONEMAPRESPONSE"))

(in-package "ROS")



(if (not (find-package "COMMON_MSGS"))
  (ros::roseus-add-msgs "common_msgs"))


(defclass common_srvs::ConeMapRequest
  :super ros::object
  :slots ())

(defmethod common_srvs::ConeMapRequest
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

(defclass common_srvs::ConeMapResponse
  :super ros::object
  :slots (_blue_cones _yellow_cones _orange_cones ))

(defmethod common_srvs::ConeMapResponse
  (:init
   (&key
    ((:blue_cones __blue_cones) (let (r) (dotimes (i 0) (push (instance common_msgs::Cone :init) r)) r))
    ((:yellow_cones __yellow_cones) (let (r) (dotimes (i 0) (push (instance common_msgs::Cone :init) r)) r))
    ((:orange_cones __orange_cones) (let (r) (dotimes (i 0) (push (instance common_msgs::Cone :init) r)) r))
    )
   (send-super :init)
   (setq _blue_cones __blue_cones)
   (setq _yellow_cones __yellow_cones)
   (setq _orange_cones __orange_cones)
   self)
  (:blue_cones
   (&rest __blue_cones)
   (if (keywordp (car __blue_cones))
       (send* _blue_cones __blue_cones)
     (progn
       (if __blue_cones (setq _blue_cones (car __blue_cones)))
       _blue_cones)))
  (:yellow_cones
   (&rest __yellow_cones)
   (if (keywordp (car __yellow_cones))
       (send* _yellow_cones __yellow_cones)
     (progn
       (if __yellow_cones (setq _yellow_cones (car __yellow_cones)))
       _yellow_cones)))
  (:orange_cones
   (&rest __orange_cones)
   (if (keywordp (car __orange_cones))
       (send* _orange_cones __orange_cones)
     (progn
       (if __orange_cones (setq _orange_cones (car __orange_cones)))
       _orange_cones)))
  (:serialization-length
   ()
   (+
    ;; common_msgs/Cone[] _blue_cones
    (apply #'+ (send-all _blue_cones :serialization-length)) 4
    ;; common_msgs/Cone[] _yellow_cones
    (apply #'+ (send-all _yellow_cones :serialization-length)) 4
    ;; common_msgs/Cone[] _orange_cones
    (apply #'+ (send-all _orange_cones :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; common_msgs/Cone[] _blue_cones
     (write-long (length _blue_cones) s)
     (dolist (elem _blue_cones)
       (send elem :serialize s)
       )
     ;; common_msgs/Cone[] _yellow_cones
     (write-long (length _yellow_cones) s)
     (dolist (elem _yellow_cones)
       (send elem :serialize s)
       )
     ;; common_msgs/Cone[] _orange_cones
     (write-long (length _orange_cones) s)
     (dolist (elem _orange_cones)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; common_msgs/Cone[] _blue_cones
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _blue_cones (let (r) (dotimes (i n) (push (instance common_msgs::Cone :init) r)) r))
     (dolist (elem- _blue_cones)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; common_msgs/Cone[] _yellow_cones
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _yellow_cones (let (r) (dotimes (i n) (push (instance common_msgs::Cone :init) r)) r))
     (dolist (elem- _yellow_cones)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; common_msgs/Cone[] _orange_cones
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _orange_cones (let (r) (dotimes (i n) (push (instance common_msgs::Cone :init) r)) r))
     (dolist (elem- _orange_cones)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(defclass common_srvs::ConeMap
  :super ros::object
  :slots ())

(setf (get common_srvs::ConeMap :md5sum-) "b7e5900e2ea08a404fe38a8b59685279")
(setf (get common_srvs::ConeMap :datatype-) "common_srvs/ConeMap")
(setf (get common_srvs::ConeMap :request) common_srvs::ConeMapRequest)
(setf (get common_srvs::ConeMap :response) common_srvs::ConeMapResponse)

(defmethod common_srvs::ConeMapRequest
  (:response () (instance common_srvs::ConeMapResponse :init)))

(setf (get common_srvs::ConeMapRequest :md5sum-) "b7e5900e2ea08a404fe38a8b59685279")
(setf (get common_srvs::ConeMapRequest :datatype-) "common_srvs/ConeMapRequest")
(setf (get common_srvs::ConeMapRequest :definition-)
      "---
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
")

(setf (get common_srvs::ConeMapResponse :md5sum-) "b7e5900e2ea08a404fe38a8b59685279")
(setf (get common_srvs::ConeMapResponse :datatype-) "common_srvs/ConeMapResponse")
(setf (get common_srvs::ConeMapResponse :definition-)
      "---
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
")



(provide :common_srvs/ConeMap "b7e5900e2ea08a404fe38a8b59685279")


