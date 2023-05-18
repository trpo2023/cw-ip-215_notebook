#include "functions.h"
int ID;

int main() {
    setlocale (LC_ALL, "rus");
    system("clear");
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t|                   Welcome to your Personal ToDo List                   |"<<endl;
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;

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
        cout<<endl<<endl;
        cout << "\n\t1.Add new note";
        cout << "\n\t2.View notes";
        cout << "\n\t3.Edit note";
        cout << "\n\t4.Exit";

        int choice;
        cout << "\n\tWhat do you want?  ";
        cin >> choice;
        switch (choice) {
        case 1:
            addtodo();
            break;
        case 2:
            readData();
            break;
        case 3:
            updateData();
            break;
        case 4:
            exit_program();
            break;
        }
    }
}