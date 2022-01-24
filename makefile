CXX=g++
LDLIBS= -lboost_filesystem -lboost_system

file: recursive_file.cpp
	$(CXX) -std=c++17 -o file recursive_file.cpp $(LDLIBS)