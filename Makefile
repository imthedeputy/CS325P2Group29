CXX = g++
CXXFLAGS = -c -std=c++98 -Wall

changegreedy.o: changegreedy.h changegreedy.cpp
	${CXX} ${CXXFLAGS} changegreedy.cpp