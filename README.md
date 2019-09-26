This serves as the repository for the code for the Wisconsin Autonomous's scale vehicle.

The ArduinoInterface package is the code that is executed by the arduino. It interfaces over serial with a Jetson AGX Xavier. It is used as an analog ECU.

The RunStopRelay and RunStopRemote provide a remote switch mechanism for sshutting off the scale vehicle in the case of an emergency.

the catkin_ws is where we maintain our ROS code. Located within the src directory in catkin_ws is the packages and drivers we use to control the scale vehicle.
