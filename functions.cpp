#include "functions.h"
extern int ID;

const char* output = "todo.txt";
const char* temp_output = "temp.txt";

void header (int n) {
	system("clear");
    if (n == 0) {
        cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
	    cout<<"\t\t\t|              Добро пожаловать в Ваш Персональный ToDo List             |"<<endl;
        cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;

    }
    if (n == 1) {
        system("clear");
        cout << "\t\t\t ------------------------------------------------------------------------" << endl;
        cout << "\t\t\t|                      Ваш персональный ToDo List                        |" << endl;
        cout << "\t\t\t ------------------------------------------------------------------------" << endl << endl;
    }
    if (n == 2) {
        header (1);
        cout << "\n\tВведите новую заметку: ";
    }
    if (n == 3) {
        header (1);
        cout << "\n\tВведите номер задачи: ";
    }
    if (n == 4) {
        system("clear");
        cout << "\n\t\t\t---------------------------Текущие задачи-----------------------------\n";
    }
}


void addtodo_user_choice () {
    string ch;
    cout << "Хотите добавить ещё? (д/н)" << endl;
    cin >> ch;

    if(ch == "д" or "да"){
        header (2);
        addtodo();
    }
    else{
        cout << "\n\tЗаметка добавлена!";
        return;
    }
}


void addtodo() {
    todo todo;
    cin.get();
    getline(cin, todo.task); 
    ID++; 

    ofstream write;
    write.open(output, ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();

    write.open("id.txt");
    write << ID;
    write.close();

    addtodo_user_choice ();
}


void print(todo s) {
    cout << "\n\t" << s.id << "." << s.task;
}


void readData() {
    todo todo;
    ifstream read; 
    read.open(output);
    
    while (!read.eof()) {
        read >> todo.id; 
        read.ignore(); 
        getline(read, todo.task); 
        print(todo); 
    }
    read.close();
}


int searchData() {
    int id; 
    cin >> id; 
    todo todo;
    ifstream read;
    read.open(output); 
    
    while (!read.eof()) {
        read >> todo.id; 
        read.ignore(); 
        getline(read, todo.task); 
        if (todo.id == id) {
            print(todo); 
            return id; 
        }
    }
    return EXIT_CODE;
}

void updateData() {
    int id = searchData(); 
    cout << "\n\tХотите изменить эту заметку? (д/н) : ";
    string ch;
    cin >> ch;
    if (ch == "д") {
        cout << "\n\tВведите новую заметку : ";
        todo newData; 
        cin.get(); 
        getline(cin, newData.task); 
        
        todo todo;
        ofstream tempFile;
        tempFile.open(temp_output); 
        ifstream read;
        read.open(output); 
        
        while (!read.eof()) {
            read >> todo.id;
            read.ignore(); 
            getline(read, todo.task);
            
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
            else {
                tempFile << "\n"<< todo.id;
                tempFile << "\n"<< newData.task;
            }
        }
        read.close(); 
        tempFile.close();
        remove(output);
        rename(temp_output, output); 
        cout << "\n\tЗаметка обновлена!";
    }
    else {
        cout << "\n\tЗаметка не обновлена";
    }
}

void exit_program() {
    exit(0);
}