#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <clocale>

using namespace std;
extern int ID;

//custom type todo which has two fields id and task
struct todo {
    int id;
    string task;
};

void header ();
void addtodo();
void print (todo s);
int searchData();
void readData();
void updateData();
void exit_program();