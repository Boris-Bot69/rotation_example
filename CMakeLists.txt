cmake_minimum_required(VERSION 3.0)
project(rotation_example)

# Find GTSAM
find_package(GTSAM REQUIRED)

# Ensure C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(rotation_example rotation_example.cpp)

# Link GTSAM
target_link_libraries(rotation_example gtsam)
