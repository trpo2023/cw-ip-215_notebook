#include <functions/functions.h>

static const char* output = "todo.txt";
static const char* temp_output = "temp.txt";

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
    if (n == 4) {
        system("clear");
        cout << "\n\t\t\t---------------------------Текущие задачи-----------------------------\n";
    }
}


void addtodo(int ID, string task) {
        ofstream write;
        write.open(output, ios::app);
        write << "\n" << ID;
        write << "\n " << task ;
        write << "\n " << "не определён";
        write.close();

        write.open("id.txt");
        write << ID;
        write.close();
}


void print(todo s) {
    cout << "\n\t" << s.id << ". " << s.task << "\n\tПриоритет: " << s.priority;
}

void readData() {
    todo todo;
    ifstream read;
    read.open(output);
    
    while (!read.eof()) {
        read >> todo.id;
        if (!todo.id)
        {
            cout << "\n\tЗаметок нет!";
            return;
        } 
        read.ignore(); 
        getline(read, todo.task);
        read.ignore();
        getline(read, todo.priority);
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
        read.ignore();
        getline(read, todo.priority); 
        if (todo.id == id) {
            print(todo); 
            return id; 
        }
    }
    return -1;
}

void updateData(int ID, string task) {
        todo todo;
        ofstream tempFile;
        tempFile.open(temp_output); 
        ifstream read;
        read.open(output); 
        
        while (!read.eof()) {
            read >> todo.id;
            read.ignore(); 
            getline(read, todo.task);
            read.ignore();
            getline(read, todo.priority);
            if (todo.id != ID) {
                tempFile << "\n" << todo.id;
                tempFile << "\n " << todo.task;
                tempFile << "\n " << todo.priority;
            }
            else {
                tempFile << "\n"<< todo.id;
                //tempFile << "\n"<< newData.task;
                tempFile << "\n "<< task;
                tempFile << "\n " << todo.priority;
            }
        }
        read.close(); 
        tempFile.close();
        remove(output);
        rename(temp_output, output); 
}

void exit_program() {
    exit(0);
}

/*void updatePriority(int ID, string priority)
{
        todo todo;
        ofstream tempFile;
        tempFile.open(temp_output); 
        ifstream read;
        read.open(output); 
        
        while (!read.eof()) {
            read >> todo.id;
            read.ignore(); 
            getline(read, todo.task);
            read.ignore();
            getline(read, todo.priority);
            if (todo.id != ID) {
                tempFile << "\n" << todo.id;
                tempFile << "\n " << todo.task;
                tempFile << "\n " << todo.priority;
            }
            else {
                tempFile << "\n"<< todo.id;
                tempFile << "\n "<< todo.task;
                tempFile << "\n " << priority;
            }
        }
        read.close(); 
        tempFile.close();
        remove(output);
        rename(temp_output, output); 
}*/

void updatePriority(int ID, string priority)
{
    todo todo;
    ofstream tempFile;
    ifstream read;
    tempFile.open(temp_output);
    read.open(output);

    if (tempFile.is_open() && read.is_open()) {
        while (read >> todo.id) {
            read.ignore();
            getline(read, todo.task);
            getline(read, todo.priority);
            if (todo.id == ID) {
                todo.priority = priority;
            }
            tempFile << todo.id << "\n" << todo.task << "\n" << todo.priority << "\n";
        }
        read.close();
        tempFile.close();
        remove(output);
        rename(temp_output, output);
    } else {
        cout << "Failed to open files for reading and writing." << endl;
    }
}

void clearAllData()
{
    remove(output);
    remove("id.txt");
}

void deltodo(int ID)
{
        todo todo;
        ofstream tempFile;
        tempFile.open(temp_output); 
        ifstream read;
        read.open(output); 
        
        while (!read.eof()) {
            read >> todo.id;
            read.ignore(); 
            getline(read, todo.task);
            read.ignore();
            getline(read, todo.priority);
            if (todo.id != ID) {
                tempFile << "\n" << todo.id;
                tempFile << "\n " << todo.task;
                tempFile << "\n " << todo.priority;
            }
        }
        read.close(); 
        tempFile.close();
        remove(output);
        rename(temp_output, output); 
}

int lastID()
{
    int ID = 0;
    ifstream read; 
    read.open("id.txt"); 

    if (!read.fail()) { 
        read >> ID; 
    }
    read.close();
    return ID;
}

void startMenu()
{
     int ID;
     string ch, task;
     while (true) {
        cout << endl << endl;
        cout << "\n\t1.Добавить заметку";
        cout << "\n\t2.Просмотреть заметки";
        cout << "\n\t3.Изменить заметку";
        cout << "\n\t4.Удалить заметку";
        cout << "\n\t5.Удалить все заметки";
        cout << "\n\t6.Изменить приоритет заметки";
        cout << "\n\t0.Выход";

        int choice;
        cout << "\n\tЧто хотите сделать?  ";
        cin >> choice;
        switch (choice) {
        case 1:
            ID = lastID() + 1;
            ch = "д";
            while (ch == "д")
            {
                cout << "\n\tВведите новую заметку: ";
                cin.get();
                getline(cin, task);
                addtodo(ID, task);
                cout << "Хотите добавить ещё? (д/н)" << endl;
                cin >> ch;
            }
            break;
        case 2:
            header (4);
            readData();
            break;
        case 3:
            header(1);
            cout << "\n\tВведите номер заметки: ";
            ID = searchData();
            if (ID == -1)
            {
                cout << "Такой заметки нет!";
                break;
            }
            header(1); 
            cout << "\n\tХотите изменить текст заметки? (д/н) : ";
            cin >> ch;
            if (ch == "д") {
                cout << "\n\tВведите новую заметку : ";                 
                cin.get(); 
                getline(cin, task);
                updateData(ID, task);
                cout << "\n\tЗаметка обновлена!";
            }
            else 
            {
                cout << "\n\tЗаметка не обновлена";
            }
            break;
        case 4:
            header (1);
            cout << "\n\tВведите номер заметки: ";
            ID = searchData();
            if (ID == -1)
            {
                cout << "Такой заметки нет!";
                break;
            }
            header (1); 
            cout << "\n\tХотите удалить эту заметку? (д/н) : ";
            cin >> ch;
            if (ch == "д") {
                deltodo(ID);
                cout << "\n\tЗаметка удалена!";
            }
            else
            {
                cout << "\n\tЗаметка не удалена!";
            }
            break;
        case 5:
            header(4);
            clearAllData();
            break;
        case 6:
            header(1);
            cout << "\n\tВведите номер заметки: ";
            ID = searchData();
            if (ID == -1)
            {
                cout << "Такой заметки нет!";
                break;
            }
            header(1); 
            cout << "\n\tХотите изменить приоритет заметки? (д/н) : ";
            cin >> ch;
            if (ch == "д") {
                cout << "\n\tУкажите приоритет : ";                 
                cin.get(); 
                getline(cin, task);
                updatePriority(ID, task);
                cout << "\n\tПриоритет изменён!";
            }
            else 
            {
                cout << "\n\tПриоритет не изменён!";
            }
            break;
        case 0:
            exit_program();
            break;
        }
    }
}

