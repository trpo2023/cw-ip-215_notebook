//#include "../functions/functions.h"
//#include "../functions/functions.cpp"
#include <functions/functions.h>
#include <functions/functions.cpp>
#include "ctest.h"

CTEST(addtodo, test_addtodo){
    int last_ID = lastID();
    string task = "Обновлённый текст";
    int new_id = last_ID + 1;
    addtodo(new_id, task);
    
    ifstream read;
    read.open(output);
    bool found = false;
    while (!read.eof()) {
        int id;
        string task, priority;
        read >> id;
        read.ignore();
        getline(read, task);
        getline(read, priority);
        if (id == new_id && task.find("Обновлённый текст") != string::npos) {
            found = true;
            break;
        }
    }
    read.close();
    
    ASSERT_TRUE(found);
}

CTEST(updateData,test_updateData)
{
    int test = 1, result = 1;
    ifstream ifs, ifs2;
    ifs.open(output);
    ofstream ofs;
    ofs.open(temp_output);
    string str, str2;
    while (std::getline(ifs,str))
        ofs << str << '\n';
    ifs.close();
    ofs.close();
    int ID = 1;
    string task = "обновлённый текст";
    updateData(ID,task);
    ifs.open(output);
    ifs2.open(temp_output);
    while(result == 1 && std::getline(ifs,str))
    {
        std::getline(ifs2,str2);
        if (str != str2) result = 0;
    }
    ifs.close();
    ifs2.close();
    ASSERT_NOT_EQUAL(test,result);
}

CTEST(updatePriority,test_updatePriority)
{
    int test = 1, result = 1;
    ifstream ifs, ifs2;
    ifs.open(output);
    ofstream ofs;
    ofs.open(temp_output);
    string str, str2;
    while (std::getline(ifs,str))
        ofs << str << '\n';
    ifs.close();
    ofs.close();
    int ID = 1;
    string task = "высокий";
    updatePriority(ID,task);
    ifs.open(output);
    ifs2.open(temp_output);
    while(result == 1 && std::getline(ifs2,str2))
    {
        std::getline(ifs,str);
        if (str != str2) result = 0;
    }
    ifs.close();
    ifs2.close();
    ASSERT_EQUAL(test,result);
}

CTEST(deltodo,test_deltodo)
{
    int test = 1, result = 1;
    ifstream ifs, ifs2;
    ifs.open(output);
    ofstream ofs;
    ofs.open(temp_output);
    string str, str2;
    while (std::getline(ifs,str))
        ofs << str << '\n';
    ifs.close();
    ofs.close();
    int ID = 1;
    deltodo(ID);
    ifs.open(output);
    ifs2.open(temp_output);
    while(result == 1 && std::getline(ifs2,str2))
    {
        if(!std::getline(ifs,str)) result = 0;
        else
            if (str != str2) result = 0;
    }
    ifs.close();
    ifs2.close();
    ASSERT_EQUAL(test,result);
}