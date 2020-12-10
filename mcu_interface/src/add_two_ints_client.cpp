#include "ros/ros.h"
#include "mcu_interface/AddTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 2)
  {
    ROS_INFO("usage: add_two_ints_client X");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<mcu_interface::AddTwoInts>("add_two_ints");
  mcu_interface::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  //srv.request.b = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %d", srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}