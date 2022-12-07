CXX = g++
CXXFLAGS = -Wall -std=c++11 

OBJECTS = setup.o nqueens.o

bard: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o nqueens setup.o nqueens.o

setup.o: setup.cpp setup.h
	$(CXX) -g $(CXXFLAGS) -c setup.cpp
	
nqueens.o: setup.cpp setup.h nqueens.cpp
	$(CXX) -g $(CXXFLAGS) -c nqueens.cpp

clean: 
	rm -f *.o
	rm nqueens
