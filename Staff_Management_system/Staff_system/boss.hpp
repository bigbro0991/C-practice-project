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
    cout<<"ְ����ţ�"<<this->m_id;
    cout<<"\tְ��������"<<setw(6)<<left<<this->m_name;
    cout<<"\t��λ��"<<this->getDeptName();
    cout<<"\t��λְ��"<<"����Ա��"<<endl;
}
string boss::getDeptName()
{
    return string("�ϰ�"); 
}
boss::~boss()
{

}