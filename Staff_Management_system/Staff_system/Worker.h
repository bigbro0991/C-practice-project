#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker
{
public:
    virtual void show_info()=0;
    virtual string getDeptName()=0;
    int m_id;
    string m_name;
    int m_Deptid;
};