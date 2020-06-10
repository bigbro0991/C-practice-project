#pragma once
#include"Worker.h"
using namespace std;

class employee: public Worker
{
public:
    employee(int id,string name, int did);
    virtual void show_info();
    virtual string getDeptName();
    ~employee();
};