all: main.exe

main.exe: main.o
	 g++ -o main.exe main.o

main.o: main.c
	 g++ -c main.c
     
clean:
	 del main.o main.exe