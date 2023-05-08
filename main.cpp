#include "functions.h"
int ID;

int main() {
    setlocale (LC_ALL, "rus");
    system("cls");
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t|                Добро пожаловать в Ваш личный ToDo List                 |"<<endl;
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
    cout<<"beta (works only with eng lang)";

    ifstream read; //создание объекта для чтения данных из файла.
    read.open("id.txt"); //открытие файла "id.txt" для чтения

    //проверка на успешное открытие
    if (!read.fail()) { 
        read >> ID; //чтение значения переменной ID из файла
    }
    else {
        ID = 0;
    }
    read.close(); //закрытие файла

    while (true) {
        cout<<endl<<endl;
        cout << "\n\t1.Добавить заметку";
        cout << "\n\t2.Просмотреть заметки";
        cout << "\n\t2.Изменить заметку";
        cout << "\n\t4.Выход";

        int choice;
        cout << "\n\tВаш выбор : ";
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