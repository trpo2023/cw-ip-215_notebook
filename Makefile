# Компилятор и флаги компиляции
CPP := g++
CPPFLAGS := -Wall -Wextra -pedantic -g -I src/functions

# Список исходных файлов
SRC := $(wildcard src/todo/*.cpp) $(wildcard src/functions/*.cpp) $(wildcard src/thirdparty/*.cpp)

# Создание файлов объектного кода
OBJ := $(src/todo/%.cpp=src/todo/%.o) $(src/functions/%.cpp=src/functions/%.o) $(src/thirdparty/%.cpp=src/thirdparty/%.o)

# Сборка исполняемого файла
all: obj/src/todo/main.exe
test: obj/src/thirdparty/main-test.exe

src/todo/main.exe: src/todo/main.o src/functions/functions.o
	g++ -o src/todo/main.exe src/todo/main.o src/functions/functions.o

src/thirdparty/main-test.exe: src/thirdparty/main-test.o src/functions/functions.o
	g++ -o src/thirdparty/main-test.exe src/thirdparty/main-test.o src/thirdparty/ctest.o src/functions/functions.o

# Компиляция исходного кода в объектные файлы
src/thirdparty/main-test.o: src/thirdparty/main-test.cpp
	g++ -c -o src/thirdparty/main-test.o src/thirdparty/main-test.cpp

src/thirdparty/ctest.o: src/thirdparty/main-test.cpp src/thirdparty/ctest.h
	g++ -c -o src/thirdparty/ctest.o src/thirdparty/ctest.cpp

src/todo/main.o: src/todo/main.cpp
	g++ -c -o src/todo/main.o src/todo/main.cpp

src/functions/functions.o: src/functions/functions.cpp src/functions/functions.h
	g++ -c -o src/functions/functions.o src/functions/functions.cpp

# Очистка
clean:
	rm src/functions/*.o src/todo/*.o src/thirdparty/*.o *.o *.txt

.PHONY: all clean

run: obj/src/todo/main.exe
	./obj/src/todo/main.exe