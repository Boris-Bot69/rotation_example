#include <iostream>
#include <Eigen/Dense>

class EulerConverter {
public:
    Eigen::Matrix3d eulerToDCM(double roll, double pitch, double yaw) {
        Eigen::Matrix3d dcm;
        
        double cosPhi = cos(roll);
        double sinPhi = sin(roll);
        double cosTheta = cos(pitch);
        double sinTheta = sin(pitch);
        double cosPsi = cos(yaw);
        double sinPsi = sin(yaw);
        
        dcm << cosTheta * cosPsi,                          -cosTheta * sinPsi,                           sinTheta,
               cosPhi * sinPsi + sinPhi * sinTheta * cosPsi, cosPhi * cosPsi - sinPhi * sinTheta * sinPsi, -sinPhi * cosTheta,
               sinPhi * sinPsi - cosPhi * sinTheta * cosPsi, sinPhi * cosPsi + cosPhi * sinTheta * sinPsi,  cosPhi * cosTheta;
    
        return dcm;
    }

    Eigen::Quaterniond eulerToQuaternion(double roll, double pitch, double yaw) {
        Eigen::Quaterniond quaternion;
        
        double cosPhi = cos(roll / 2);
        double sinPhi = sin(roll / 2);
        double cosTheta = cos(pitch / 2);
        double sinTheta = sin(pitch / 2);
        double cosPsi = cos(yaw / 2);
        double sinPsi = sin(yaw / 2);
        
        quaternion.w() = cosPhi * cosTheta * cosPsi + sinPhi * sinTheta * sinPsi;
        quaternion.x() = sinPhi * cosTheta * cosPsi - cosPhi * sinTheta * sinPsi;
        quaternion.y() = cosPhi * sinTheta * cosPsi + sinPhi * cosTheta * sinPsi;
        quaternion.z() = cosPhi * cosTheta * sinPsi - sinPhi * sinTheta * cosPsi;
    
        return quaternion;
    }
};

int main() {
    EulerConverter converter;

    double roll = 0.1;    // Replace with your desired Euler angles
    double pitch = 0.2;
    double yaw = 0.3;

    Eigen::Matrix3d dcm = converter.eulerToDCM(roll, pitch, yaw);
    Eigen::Quaterniond quaternion = converter.eulerToQuaternion(roll, pitch, yaw);

    std::cout << "Direction Cosine Matrix (DCM):\n" << dcm << std::endl;
    std::cout << "Quaternion:\n" << quaternion.coeffs() << std::endl;

    return 0;
}

