#pragma once
#include<iostream>
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define fiename "empFile.txt"
using namespace std;

class WorkManager
{
    public:
    WorkManager();
    void sort_emp();
    void show_menu();
    void show_emp();
    void del_emp();
    void mod_emp();
    void find_emp();
    void clean_file();
    int  isexist(int id);
    void exit_system();
    void save();
    int num_emp;
    int get_num_emp();
    bool fileisempty;
    Worker **emp_array;
    void addemp();
    void emp_init();
    ~WorkManager();
};