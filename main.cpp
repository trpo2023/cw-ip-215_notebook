#include "functions.h"

//const char* output = "todo.txt";
//const char* temp_output = "temp.txt";

int ID;

int main() {
    setlocale (LC_ALL, "rus");
    //system("clear");
    header (0);

    ifstream read; 
    read.open("id.txt"); 


    if (!read.fail()) { 
        read >> ID; 
    }
    else {
        ID = 0;
    }
    read.close(); 

    while (true) {
        cout << endl << endl;
        cout << "\n\t1.Добавить заметку";
        cout << "\n\t2.Просмотреть заметки";
        cout << "\n\t3.Изменить заметку";
        cout << "\n\t4.Выход";

        int choice;
        cout << "\n\tЧто хотите сделать?  ";
        cin >> choice;
        switch (choice) {
        case 1:
            header (2);
            addtodo();
            break;
        case 2:
            header (4);
            readData();
            break;
        case 3:
            header (3);
            updateData();
            break;
        case 4:
            exit_program();
            break;
        }
    }
}