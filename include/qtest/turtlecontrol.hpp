
#ifndef turtlecontrol_HPP_
#define turtlecontrol_HPP_


#include <ros/ros.h>
#include <stdio.h>

class TurtleControl
{
public:
  TurtleControl(int argc, char** argv);
  void sendVel(int angular, int linear);

private:
  ros::NodeHandle nh_;
  double linear_, angular_, l_scale_, a_scale_;
  ros::Publisher twist_pub_;
  
};

#endif