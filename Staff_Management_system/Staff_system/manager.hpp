#include"manager.h"


manager::manager(int id,string name, int did)
{
    m_Deptid=did;
    m_id=id;
    m_name=name;
}
void manager::show_info()
{       
    cout<<"ְ����ţ�"<<this->m_id;
    cout<<"\tְ��������"<<setw(6)<<this->m_name;
    cout<<"\t��λ��"<<this->getDeptName();
    cout<<"\t��λְ��"<<"���������ϰ������"<<endl;
}
string manager::getDeptName()
{
    return string("����"); 
}
manager::~manager()
{

}