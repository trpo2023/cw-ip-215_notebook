#include "functions.h"
int ID;

int main() {
    setlocale (LC_ALL, "rus");
    system("cls");
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t|                ����� ���������� � ��� ������ ToDo List                 |"<<endl;
    cout<<"\t\t\t ------------------------------------------------------------------------"<<endl;
    cout<<"beta (works only with eng lang)";

    ifstream read; //�������� ������� ��� ������ ������ �� �����.
    read.open("id.txt"); //�������� ����� "id.txt" ��� ������

    //�������� �� �������� ��������
    if (!read.fail()) { 
        read >> ID; //������ �������� ���������� ID �� �����
    }
    else {
        ID = 0;
    }
    read.close(); //�������� �����

    while (true) {
        cout<<endl<<endl;
        cout << "\n\t1.�������� �������";
        cout << "\n\t2.����������� �������";
        cout << "\n\t2.�������� �������";
        cout << "\n\t4.�����";

        int choice;
        cout << "\n\t��� ����� : ";
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