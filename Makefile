# Компилятор и флаги компиляции
CPP := g++
CPPFLAGS := -Wall -Wextra -pedantic -g -I src/functions

# Список исходных файлов
SRC := $(wildcard src/todo/*.cpp) $(wildcard src/functions/*.cpp)

# Создание файлов объектного кода
OBJ := $(SRC:%.cpp=obj/%.o)

# Сборка исполняемого файла
all: obj/src/todo/main.exe

obj/src/todo/main.exe: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Компиляция исходного кода в объектные файлы
obj/%.o: %.cpp | obj/src/todo obj/src/functions
	$(CPP) $(CPPFLAGS) -c $< -o $@

obj/src/todo:
	mkdir -p $@

obj/src/functions:
	mkdir -p $@

# Очистка
clean:
	rm -rf obj/src todo/main.obj *.o *.txt

.PHONY: all clean

run: obj/src/todo/main.exe
	./obj/src/todo/main.exe