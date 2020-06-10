#include"employee.h"
#include <iomanip>

employee::employee(int id,string name, int did)
{
    m_Deptid=did;
    m_id=id;
    m_name=name;
}
void employee::show_info()
{       
    cout<<"职工编号："<<this->m_id;
    cout<<"\t职工姓名："<<setw(6)<<this->m_name;
    cout<<"\t岗位："<<this->getDeptName();
    cout<<"\t岗位职责："<<"完成经理下发的任务"<<endl;
}
string employee::getDeptName()
{
    return string("员工"); 
}
employee::~employee()
{

}