CXX=g++
EIGEN_DIR = /home/ge25sat/eigen-3.4.0
GTSAM_DIR = /home/ge25sat/gtsam
CXXFLAGS=-std=c++17 -I$(GTSAM_DIR)/include -I$(EIGEN_DIR)
LDFLAGS=-L$(GTSAM_DIR)/lib -lgtsam

rotation_example: rotation_example.cpp 
	$(CXX) $(CXXFLAGS) -o rotation_example rotation_example.cpp $(LDFLAGS)
	chmod +x rotation_example

run: rotation_example
	export LD_LIBRARY_PATH=$(GTSAM_DIR)/lib:$$LD_LIBRARY_PATH; ./rotation_example
