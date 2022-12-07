CXX = g++
CXXFLAGS = -Wall

sixdegrees: sixdegrees.o
	$(CXX) -g $(CXXFLAGS) -o sixdegrees sixdegrees.o

sixdegrees.o: sixdegrees.cpp
	$(CXX) -g $(CXXFLAGS) -c sixdegrees.cpp

clean: 
	rm -f *.o
	rm sixdegrees
