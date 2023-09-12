# rotation_example
GTSAM library with examples and tests

Google Test:
Installation:

sudo apt-get install libgtest-dev
sudo apt-get install cmake # Install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make


Compile the test:

g++ -o test_rotation test_rotation.cpp -std=c++17 -lgtest -lgtest_main -pthread -lgtsam -I ~/eigen-3.4.0
(Important: Last argument is the directory of the installed Eigenlibrary)

Run the test:
./test_rotation

--------------------------------------------------------------------------------------------------------------

The class EulerConverter.cpp is the class using only Eigen library, tests still in progress (not uploaded yet)


