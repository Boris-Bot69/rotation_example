CXX=g++
EIGEN_DIR = /mnt/c/Users/boris/OneDrive/Dokumente/eigen-3.4.0 #replace this with your path
GTSAM_DIR = /mnt/c/Users/boris/OneDrive/Dokumente/gtsam #replace this with your path
CXXFLAGS=-std=c++17 -I$(GTSAM_DIR)/include -I$(EIGEN_DIR)
LDFLAGS=-L$(GTSAM_DIR)/lib -lgtsam

rotation_example: rotation_example.cpp 
	$(CXX) $(CXXFLAGS) -o rotation_example rotation_example.cpp $(LDFLAGS)
	

run: rotation_example
	export LD_LIBRARY_PATH=$(GTSAM_DIR)/lib:$$LD_LIBRARY_PATH; ./rotation_example


