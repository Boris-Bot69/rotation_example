#include <gtest/gtest.h>
#include <gtsam/geometry/Rot3.h>

TEST(Rot3Tests, MatrixConstructor) {
  gtsam::Matrix3 matrix;
  matrix << 1, 0, 0,
            0, 1, 0,
            0, 0, 1;
  gtsam::Rot3 R(matrix);
  ASSERT_TRUE(R.matrix().isApprox(matrix));
}

TEST(Rot3Tests, QuaternionConstructor) {
  gtsam::Quaternion quaternion(1, 0, 0, 0);
  gtsam::Rot3 R(quaternion);
  // Define the expected rotation matrix for the given quaternion
  gtsam::Matrix3 expected_matrix;
  expected_matrix << 1, 0, 0,
                     0, 1, 0,
                     0, 0, 1;
  ASSERT_TRUE(R.matrix().isApprox(expected_matrix));
}

TEST(Rot3Tests, YprConstructor) {
  double roll = 0.1, pitch = 0.2, yaw = 0.3;
  gtsam::Rot3 R = gtsam::Rot3::Ypr(yaw, pitch, roll);
  // Define the expected rotation matrix for the given yaw, pitch, and roll
  gtsam::Matrix3 expected_matrix;
  // Calculate the expected matrix based on the Euler angles
  // You may use a library or tool to compute this or manually define it
  // expected_matrix << ...
  ASSERT_TRUE(R.matrix().isApprox(expected_matrix));
}













int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

