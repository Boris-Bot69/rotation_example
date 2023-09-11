#include <gtsam/geometry/Rot3.h>
#include <iostream>

// Forward declarations
gtsam::Rot3 euler_to_Rot3(double roll, double pitch, double yaw);
gtsam::Quaternion euler_to_Quaternion(double roll, double pitch, double yaw);
gtsam::Vector3 Quaternion_to_euler(const gtsam::Quaternion& quat);
gtsam::Matrix3 euler_to_DCM(double roll, double pitch, double yaw);
gtsam::Vector3 DCM_to_euler(const gtsam::Matrix3& dcm);
gtsam::Quaternion rotVec_to_Quaternion(const gtsam::Point3& rotVec);
gtsam::Point3 Quaternion_to_rotVec(const gtsam:: Quaternion& quat);


//https://github.com/haidai/gtsam/blob/master/gtsam/geometry/Rot3.h

int main()  {
  
    double roll = M_PI/3, pitch = M_PI/3, yaw = M_PI/2;
    // Euler to Quaternion


    gtsam::Quaternion quaternion = euler_to_Quaternion(roll, pitch, yaw);
    std::cout << "Quaternion (from Euler angle):\n" << quaternion << std::endl;

    // Quaternion to Euler
    gtsam::Vector3 euler = Quaternion_to_euler(quaternion);
    std::cout << "Euler angle (from Quaternion):\n" << euler.transpose() << std::endl;
    // Euler to DCM

    gtsam::Matrix3 dcm = euler_to_DCM(roll, pitch, yaw);
    std::cout << "DCM (from Euler angle):\n" << dcm << std::endl;

    // DCM to Euler
    gtsam::Vector3 euler2 = DCM_to_euler(dcm);
    std::cout << "Euler angle (from DCM):\n" << euler2.transpose() << std::endl;

    // Rotation vector to Quaternion
    gtsam::Point3 rotationVector(roll, pitch, yaw);
    gtsam::Quaternion quaternion2 = rotVec_to_Quaternion(rotationVector);
    std::cout << "Quaternion (from Rotation Vector):\n" << quaternion2 << std::endl;

    gtsam::Point3 rotVec = Quaternion_to_rotVec(quaternion2);
    std::cout << "Rotation Vector (from Quaternion):\n" << rotVec.transpose() << std::endl;
    
    return 0;
}

// Euler to Quaternion
gtsam::Rot3 euler_to_Rot3(double roll, double pitch, double yaw) {
    return gtsam::Rot3::RzRyRx(roll, pitch, yaw); // Note the order of arguments
}

gtsam::Quaternion euler_to_Quaternion(double roll, double pitch, double yaw) {
    gtsam::Rot3 rotation = euler_to_Rot3(roll, pitch, yaw);
    std::cout << "Rotationmatrix:\n" << rotation << std::endl;

    return rotation.toQuaternion();
}

// Quaternion to Euler
gtsam::Vector3 Quaternion_to_euler(const gtsam::Quaternion& quat) {
    gtsam::Rot3 rotation(quat);
    return rotation.rpy();
}

// Euler to Direction Cosine Matrix
gtsam::Matrix3 euler_to_DCM(double roll, double pitch, double yaw) {
    gtsam::Rot3 rotation = euler_to_Rot3(roll, pitch, yaw);
    return rotation.matrix();

}

// Direction Cosine Matrix to Euler
gtsam::Vector3 DCM_to_euler(const gtsam::Matrix3& dcm) {
    gtsam::Rot3 rotation(dcm);
    return rotation.rpy();
}

// Rotation vector to quaternions

// src: https://math.stackexchange.com/questions/40164/how-do-you-rotate-a-vector-by-a-unit-quaternion

gtsam::Quaternion rotVec_to_Quaternion(const gtsam::Point3& rotVec) {
  double theta = rotVec.norm();
  gtsam::Point3 p = rotVec.normalized();

  double qw = cos(theta/2.0);
  double qx = p.x() * sin(theta / 2.0);
  double qy = p.y() * sin(theta / 2.0);
  double qz = p.z() * sin(theta / 2.0);

  return gtsam::Quaternion(qw, qx, qy, qz);
}

// quaternions to rotation vector

gtsam::Point3 Quaternion_to_rotVec(const gtsam:: Quaternion& quat) {

  double theta = 2 * acos(quat.w());
  gtsam::Point3 k(quat.x(), quat.y(), quat.z());

  if (theta > 2.0) {
    k = k / sin(theta/ 2.0);
  }
  return k * theta;
}