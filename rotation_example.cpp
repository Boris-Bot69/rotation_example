#include <gtsam/geometry/Rot3.h>
#include <iostream>

int main()  {
  // Create a Rot3 object from a rotation matrix
  gtsam::Matrix3 matrix;
  matrix << 1, 0, 0,
            0, 1, 0,
            0, 0, 1;
  gtsam::Rot3 R1(matrix);

  // Print the resulting rotation
  std::cout << "R1 (Euler Angle):\n" << R1.matrix() << std::endl;

  // Create a Rot3 object from a quaternion
  gtsam::Quaternion quaternion(1, 0, 0, 0);
  gtsam::Rot3 R2(quaternion);

  // Print the resulting rotation
  std::cout << "R2 (Quaternion):\n" << R2.matrix() << std::endl;

  double roll = 0.1, pitch = 0.2, yaw = 0.3;
  gtsam::Rot3 R3 = gtsam::Rot3::Ypr(yaw, pitch, roll);

  // Print the resulting rotation
  std::cout << "R3 (Roll, pitch, yaw):\n" << R3.matrix() << std::endl;

  gtsam::Vector3 axis(1, 0, 0);  // Changed Point3 to Vector3
  double angle = M_PI / 4;
  gtsam::Vector3 axis_angle = axis * angle;  // New line: compute the axis-angle vector
  gtsam::Rot3 R4 = gtsam::Rot3::Rodrigues(axis_angle);  // Use the axis-angle vector

  // Print the resulting rotation
  std::cout << "R4 (axis vector):\n" << R4.matrix() << std::endl;
  return 0;
}
