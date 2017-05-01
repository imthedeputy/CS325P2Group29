CXX = g++
FLAGS = -c -std=c++11 -Wall

fileprog: helperFunctions.o FileInAndOut.o
	${CXX} ${FLAGS} -o fileprog main.cpp helperFunctions.o FileInAndOut.o

FileInAndOut.o: FileInAndOut.cpp FileInAndOut.hpp changeInfo.hpp
	${CXX} ${FLAGS} FileInAndOut.cpp

helperFunctions.o: helperFunctions.cpp helperFunctions.hpp changeInfo.hpp
	${CXX} ${FLAGS} helperFunctions.cpp

experimentprog: helperFunctions.o FileInAndOut.o
	${CXX} -o experimentprog experimental.cpp helperFunctions.o FileInAndOut.o

all: fileprog experimentprog

default: fileprog

clean:
	rm -f *.o fileprog experimentprog
	rm -f AmountChange.txt
