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
    cout<<"ְ����ţ�"<<this->m_id;
    cout<<"\tְ��������"<<setw(6)<<this->m_name;
    cout<<"\t��λ��"<<this->getDeptName();
    cout<<"\t��λְ��"<<"��ɾ����·�������"<<endl;
}
string employee::getDeptName()
{
    return string("Ա��"); 
}
employee::~employee()
{

}