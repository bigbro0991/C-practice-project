#pragma once
#include"Worker.h"
using namespace std;

class manager: public Worker
{
public:
    manager(int id,string name, int did);
    virtual void show_info();
    virtual string getDeptName();
    ~manager();
};