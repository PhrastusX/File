CXX=g++
LDLIBS= -lboost_filesystem -lboost_system
STD= -std=c++17

file: recursive_file.cpp
	$(CXX) $(STD) -o recursive_file recursive_file.cpp $(LDLIBS)