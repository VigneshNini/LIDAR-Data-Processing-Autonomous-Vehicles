#!/usr/bin/env python

import rospy
from nav_msgs.msg import OccupancyGrid
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import PoseWithCovarianceStamped
from tf.transformations import euler_from_quaternion

class SlamMappingNode:
    def __init__(self):
        rospy.init_node('slam_mapping', anonymous=True)
        
        # Subscribers
        rospy.Subscriber("/scan", LaserScan, self.lidar_callback)
        rospy.Subscriber("/map", OccupancyGrid, self.map_callback)
        rospy.Subscriber("/amcl_pose", PoseWithCovarianceStamped, self.pose_callback)

        # Data containers
        self.current_map = None
        self.robot_pose = None

    def lidar_callback(self, data):
        # Process the LiDAR data for SLAM
        rospy.loginfo("Received LiDAR scan with %d ranges" % len(data.ranges))
        # Note: `gmapping` will handle the data processing, but we monitor it here.

    def map_callback(self, data):
        # Receive the generated map
        self.current_map = data
        rospy.loginfo("Map updated with resolution %f and size [%d, %d]" %
                      (data.info.resolution, data.info.width, data.info.height))
        # Save or display map data as needed (e.g., visualization or storage)

    def pose_callback(self, data):
        # Obtain robot's current pose
        position = data.pose.pose.position
        orientation_q = data.pose.pose.orientation
        orientation = euler_from_quaternion([orientation_q.x, orientation_q.y,
                                             orientation_q.z, orientation_q.w])
        self.robot_pose = (position.x, position.y, orientation[2])  # X, Y, Yaw
        rospy.loginfo("Robot Pose - X: %.2f, Y: %.2f, Yaw: %.2f" % self.robot_pose)

    def run(self):
        rospy.spin()

if __name__ == '__main__':
    try:
        slam_node = SlamMappingNode()
        slam_node.run()
    except rospy.ROSInterruptException:
        pass
