#pragma once
#include"Worker.h"
using namespace std;

class boss : public Worker
{
public:
    boss(int id,string name, int did);
    virtual void show_info();
    virtual string getDeptName();
    ~boss();
};