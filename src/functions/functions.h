#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <clocale>

using namespace std;

//constexpr int EXIT_CODE = -1;
//extern int ID;

struct todo {
    int id;
    string task;
    string priority;
};

void header (int n);
void addtodo(int ID, string task);
void print (todo s);
int searchData();
void readData();
void updateData(int ID, string task);
void exit_program();
void deltodo(int ID);
void updatePriority(int ID, string priority);
void clearAllData();
void startMenu();
int lastID();

#endif
