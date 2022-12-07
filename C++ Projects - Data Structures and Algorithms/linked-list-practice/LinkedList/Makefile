CXX = g++
CXXFLAGS = -Wall

OBJECTS = linkedlist.o listwrapper.o

listwrapper: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o listwrapper linkedlist.o listwrapper.o

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CXX) -g $(CXXFLAGS) -c linkedlist.cpp
	
listwrapper.o: linkedlist.cpp linkedlist.h listwrapper.cpp
	$(CXX) -g $(CXXFLAGS) -c listwrapper.cpp

clean: 
	rm -f *.o
	rm listwrapper