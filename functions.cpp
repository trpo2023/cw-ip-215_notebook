#include <iostream>
#include "functions.h"
extern int ID;

void header () {
	system("cls");
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t|                          Ваш личный ToDo List                          |"<<endl;
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl<<endl;
}

//добавление новой заметки
void addtodo() {
	header ();
    todo todo;
    cout << "\n\tВведите новую заметку: ";
    cin.get();
    getline(cin, todo.task); //ввод пользователя
    ID++; //увеличиваем номер для текущей заметки

    //запись заметок в файл
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();

    //записываем номера заметок в отдельный файл для последующего добавления новых заметок
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"Do you want to add another? y/n"<<endl;
    cin>> ch;

    //на случай, если пользователь захочет добавить несколько заметок
    if(ch == 'y'){
        addtodo();
    }
    else{
        cout << "\n\tЗаметка добавлена!";
        return;
    }
}

// вывод заметок на экран
void print(todo s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}

//чтение заметок из файла
void readData() {
    header ();
    todo todo;
    ifstream read; 
    read.open("todo.txt");//объект для чтения из файла
    cout << "\n\t-------------------------Ваши текущие заметки--------------------------";
    // чтение из файла происходит до тех пор, пока не достигнут конец файла
    while (!read.eof()) {
        read >> todo.id; //чтение значения номера заметки из файла в структуру
        read.ignore(); //игнорирование первого символа строки файла
        getline(read, todo.task); //чтение заметки из файла
        print(todo); //вывод структуры
    }
    read.close(); //закрытие файла
}

int searchData() {
    header ();
    int id; //переменная для хранения номера заметки
    cout << "\n\tEnter task id: ";
    cin >> id; //пользователь вводит номер заметки
    todo todo;
    ifstream read;
    read.open("todo.txt"); //объект для чтения из файла
    //пока не достигли конца ищем id, введённый пользователем
    while (!read.eof()) {
        read >> todo.id; //чтение значения номера заметки из файла в структуру
        read.ignore(); //игнорирование первого символа строки файла
        getline(read, todo.task); //чтение заметки из файла
        if (todo.id == id) {
            print(todo); //если нашли нужный номер, то выводим заметку
            return id; //возвращаем найденный номер заметки
        }
    }
}

void updateData() {
    header ();
    int id = searchData(); //ищем номер заметки
    cout << "\n\tВы хотите изменить эту заметку (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData; //создание новой переменной типа todo, которая будет хранить новые данные для заметки
        cout << "\n\tВведите заметку : ";
        cin.get(); 
        getline(cin, newData.task); //ввод заметки
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt"); //запись обновленных данных в временный файл
        ifstream read;
        read.open("todo.txt"); //запись обновленных данных в постоянный файл
        //пока не достигли конца ищем id, введённый пользователем
        while (!read.eof()) {
            read >> todo.id;//чтение значения номера заметки из файла в структуру
            read.ignore(); //игнорирование первого символа строки в файле
            getline(read, todo.task);//чтение заметки из файла
            //проверка на совпадение номеров заметки
            //если условие выполняется, то записываем в временный файл
            //иначе то строка задачи заменяется на новую строку и записывается в временный файл
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
            else {
                tempFile << "\n"<< todo.id;
                tempFile << "\n"<< newData.task;
            }
        }
        read.close(); //закрываем исходный файл
        tempFile.close(); //закрываем временный файл
        remove("todo.txt"); //удаляем исходный файд
        rename("temp.txt", "todo.txt"); //переименовываем временный в исходный
        cout << "\n\tЗаметка успешна обновлена!";
    }
    else {
        cout << "\n\tЗапись не удалена";
    }
}

void exit_program() {
    exit(0);
}