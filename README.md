# rotation_example
GTSAM library with examples and tests

Google Test: <br />
Installation: <br />
<br />

sudo apt-get install libgtest-dev <br />
sudo apt-get install cmake # Install cmake <br />
cd /usr/src/gtest <br />
sudo cmake CMakeLists.txt <br />
sudo make <br />
<br />

Compile the test: <br />

g++ -o test_rotation test_rotation.cpp -std=c++17 -lgtest -lgtest_main -pthread -lgtsam -I ~/eigen-3.4.0 <br />
(Important: Last argument is the directory of the installed Eigenlibrary) <br />

Run the test: <br />
./test_rotation <br />

--------------------------------------------------------------------------------------------------------------

The class EulerConverter.cpp is the class using only Eigen-library, tests still in progress (not uploaded yet)


