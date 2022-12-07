CXX = g++
CXXFLAGS = -Wall -std=c++11 

OBJECTS = setup.o bard.o

bard: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o bard setup.o bard.o

setup.o: setup.cpp setup.h
	$(CXX) -g $(CXXFLAGS) -c setup.cpp
	
bard.o: setup.cpp setup.h bard.cpp
	$(CXX) -g $(CXXFLAGS) -c bard.cpp

clean: 
	rm -f *.o
	rm bard
