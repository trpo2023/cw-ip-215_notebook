#include <iostream>
#include "functions.h"
extern int ID;

void header () {
	system("cls");
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t|                          ��� ������ ToDo List                          |"<<endl;
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl<<endl;
}

//���������� ����� �������
void addtodo() {
	header ();
    todo todo;
    cout << "\n\t������� ����� �������: ";
    cin.get();
    getline(cin, todo.task); //���� ������������
    ID++; //����������� ����� ��� ������� �������

    //������ ������� � ����
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();

    //���������� ������ ������� � ��������� ���� ��� ������������ ���������� ����� �������
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout<<"Do you want to add another? y/n"<<endl;
    cin>> ch;

    //�� ������, ���� ������������ ������� �������� ��������� �������
    if(ch == 'y'){
        addtodo();
    }
    else{
        cout << "\n\t������� ���������!";
        return;
    }
}

// ����� ������� �� �����
void print(todo s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}

//������ ������� �� �����
void readData() {
    header ();
    todo todo;
    ifstream read; 
    read.open("todo.txt");//������ ��� ������ �� �����
    cout << "\n\t-------------------------���� ������� �������--------------------------";
    // ������ �� ����� ���������� �� ��� ���, ���� �� ��������� ����� �����
    while (!read.eof()) {
        read >> todo.id; //������ �������� ������ ������� �� ����� � ���������
        read.ignore(); //������������� ������� ������� ������ �����
        getline(read, todo.task); //������ ������� �� �����
        print(todo); //����� ���������
    }
    read.close(); //�������� �����
}

int searchData() {
    header ();
    int id; //���������� ��� �������� ������ �������
    cout << "\n\tEnter task id: ";
    cin >> id; //������������ ������ ����� �������
    todo todo;
    ifstream read;
    read.open("todo.txt"); //������ ��� ������ �� �����
    //���� �� �������� ����� ���� id, �������� �������������
    while (!read.eof()) {
        read >> todo.id; //������ �������� ������ ������� �� ����� � ���������
        read.ignore(); //������������� ������� ������� ������ �����
        getline(read, todo.task); //������ ������� �� �����
        if (todo.id == id) {
            print(todo); //���� ����� ������ �����, �� ������� �������
            return id; //���������� ��������� ����� �������
        }
    }
}

void updateData() {
    header ();
    int id = searchData(); //���� ����� �������
    cout << "\n\t�� ������ �������� ��� ������� (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        todo newData; //�������� ����� ���������� ���� todo, ������� ����� ������� ����� ������ ��� �������
        cout << "\n\t������� ������� : ";
        cin.get(); 
        getline(cin, newData.task); //���� �������
        todo todo;
        ofstream tempFile;
        tempFile.open("temp.txt"); //������ ����������� ������ � ��������� ����
        ifstream read;
        read.open("todo.txt"); //������ ����������� ������ � ���������� ����
        //���� �� �������� ����� ���� id, �������� �������������
        while (!read.eof()) {
            read >> todo.id;//������ �������� ������ ������� �� ����� � ���������
            read.ignore(); //������������� ������� ������� ������ � �����
            getline(read, todo.task);//������ ������� �� �����
            //�������� �� ���������� ������� �������
            //���� ������� �����������, �� ���������� � ��������� ����
            //����� �� ������ ������ ���������� �� ����� ������ � ������������ � ��������� ����
            if (todo.id != id) {
                tempFile << "\n" << todo.id;
                tempFile << "\n" << todo.task;
            }
            else {
                tempFile << "\n"<< todo.id;
                tempFile << "\n"<< newData.task;
            }
        }
        read.close(); //��������� �������� ����
        tempFile.close(); //��������� ��������� ����
        remove("todo.txt"); //������� �������� ����
        rename("temp.txt", "todo.txt"); //��������������� ��������� � ��������
        cout << "\n\t������� ������� ���������!";
    }
    else {
        cout << "\n\t������ �� �������";
    }
}

void exit_program() {
    exit(0);
}