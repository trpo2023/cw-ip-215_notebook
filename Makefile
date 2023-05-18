all: main.exe

main.exe: main.o functions.o
	g++ -o main.exe main.o functions.o

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp functions.h
	g++ -c functions.cpp
     
clean:
	del main.o main.exe functions.o