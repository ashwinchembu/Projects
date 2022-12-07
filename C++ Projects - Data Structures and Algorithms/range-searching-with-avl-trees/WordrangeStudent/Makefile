CXX = g++
CXXFLAGS = -Wall

wordrange: wordrange.o
	$(CXX) -g $(CXXFLAGS) -o wordrange wordrange.o

wordrange.o: wordrange.cpp
	$(CXX) -g $(CXXFLAGS) -c wordrange.cpp

clean: 
	rm -f *.o
	rm wordrange
