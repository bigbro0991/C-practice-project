#include"boss.h"
#include <iomanip>

boss::boss(int id,string name, int did)
{
    m_Deptid=did;
    m_id=id;
    m_name=name;
}
void boss::show_info()
{       
    cout<<"职工编号："<<this->m_id;
    cout<<"\t职工姓名："<<setw(6)<<left<<this->m_name;
    cout<<"\t岗位："<<this->getDeptName();
    cout<<"\t岗位职责："<<"管理员工"<<endl;
}
string boss::getDeptName()
{
    return string("老板"); 
}
boss::~boss()
{

}