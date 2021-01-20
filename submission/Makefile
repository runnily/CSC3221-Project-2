CXX=g++ -std=c++11

test: shape.o square.o circle.o game.o
	$(CXX) -o test shape.o square.o circle.o game.o

shape.o: shape.cpp shape.h
	$(CXX) -c -Wall -pedantic shape.cpp

square.o: square.cpp square.h
	$(CXX) -c -Wall -pedantic square.cpp

circle.o: circle.cpp circle.h
	$(CXX) -c -Wall -pedantic circle.cpp

game.o: game.cpp game.h
	$(CXX) -c -Wall -pedantic game.cpp
