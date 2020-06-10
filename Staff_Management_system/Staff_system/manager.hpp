#include"manager.h"


manager::manager(int id,string name, int did)
{
    m_Deptid=did;
    m_id=id;
    m_name=name;
}
void manager::show_info()
{       
    cout<<"职工编号："<<this->m_id;
    cout<<"\t职工姓名："<<setw(6)<<this->m_name;
    cout<<"\t岗位："<<this->getDeptName();
    cout<<"\t岗位职责："<<"传达和完成老板的任务"<<endl;
}
string manager::getDeptName()
{
    return string("经理"); 
}
manager::~manager()
{

}