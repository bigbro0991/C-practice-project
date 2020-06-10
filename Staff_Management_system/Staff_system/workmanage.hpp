#include "workmanage.h"
#include <string>
#include <typeinfo.h>
WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(fiename,ios::in);
	if (!ifs.is_open())
	{	
		this->num_emp=0;
		this->emp_array=NULL;
		this->fileisempty=true;
		ifs.close();
		return;
	}
	char ch;
	ifs>>ch;
	if (ifs.eof())
	{	
	
		this->num_emp=0;
		this->emp_array=NULL;
		this->fileisempty=true;
		ifs.close();
		return;
	}
	this->fileisempty=false;
	int n=this->get_num_emp();
	this->num_emp=n;
	this->emp_array=new Worker*[this->num_emp];
	this->emp_init();
}

void WorkManager::show_menu()
{
    cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
    cout<<endl;
}

void WorkManager::show_emp()
{

	ifstream ifs;
	ifs.open(fiename,ios::in);
	char ch;
	ifs>>ch;
	if (ifs.eof())
	{	
		this->num_emp=0;
		this->emp_array=NULL;
		this->fileisempty=true;
		ifs.close();
	}
	if(this->fileisempty)
	{
		cout<<"��¼Ϊ��"<<endl;
	}
	else
	for(int i=0;i<this->num_emp;i++)
	{
		this->emp_array[i]->show_info();
	}
	system("pause");
    system("cls");
}


void WorkManager::del_emp()
{
	if(this->fileisempty)
	{
		cout<<"��¼Ϊ��"<<endl;
		return;
	}
	int Id;
	cout<<"������Ҫɾ����Ա�����:"<<endl;
	cin>>Id;
	int ret=this->isexist(Id);
	if(ret!=-1)
	{
		for(int i =ret; i<this->num_emp-1;i++)
		{
			this->emp_array[i]=this->emp_array[i+1];
		}
		this->num_emp--;
		this->save();
		cout<<"ɾ���ɹ�"<<endl;
	}
	else
	{
		cout<<"ɾ��ʧ�ܣ�ְ��������"<<endl;
	}
	system("pause");
	system("cls");
	
}

void WorkManager::mod_emp()
{
	if(this->fileisempty)
	{
		cout<<"��¼Ϊ��"<<endl;
		return;
	}
	int Id;
	cout<<"������Ҫ�޸ĵ�Ա�����:"<<endl;
	cin>>Id;
	int ret=this->isexist(Id);
	if(ret!=-1)
	{

		cout << "��ѯ��" <<emp_array[ret]->m_id<< "��ְ��" << endl;
		emp_array[ret]->show_info();
		delete this->emp_array[ret];
		int ID;
		string name;
		int depnum;
		

		cout << "�������µ�Ա����"<<endl;
		cin >> ID;


		cout << "�������µ�ְ������"<<endl;
		cin >> name;


		cout << "��ѡ���ְ���ĸ�λ��" << endl;
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
		cin >> depnum;


		Worker * worker = NULL;

		switch (depnum)
		{
		case 1:
			worker=new employee(ID,name,depnum);
			break;
		case 2:
			worker=new manager(ID,name,depnum);
			break;
		case 3:
			worker=new boss(ID,name,depnum);
			break;
		default:
			break;
		}
		this->emp_array[ret]=worker;
		this->save();
		cout<<"�޸ĳɹ�"<<endl;
	}
	else
	{
		cout<<"�޸�ʧ�ܣ�ְ��������"<<endl;
	}
	system("pause");
	system("cls");
}


void WorkManager::find_emp()
{
	if(this->fileisempty)
	{
		cout<<"��¼Ϊ��"<<endl;
		system("pause");
    	system("cls");
		return;
	}
	int select;
	cout<<"��ѡ����ҷ�ʽ��1. ��Ա����Ų��� 2. ����������"<<endl;
	cin>>select;
	if(select==1)
	{
		int Id;
		cout<<"������Ҫ�޸ĵ�Ա�����:"<<endl;
		cin>>Id;
		int ret=this->isexist(Id);
		if(ret!=-1)
		{
			emp_array[ret]->show_info();
		}
		else
	    {
		cout<<"ְ��������"<<endl;
	    }
	}
	else if(select==2)
	{
	    string Name;
		bool flag=false;
		cout<<"������Ҫ�޸ĵ�Ա������:"<<endl;
		cin>>Name;
		for(int i=0; i<this->num_emp;i++)
		{
			if(this->emp_array[i]->m_name==Name)
			{
				emp_array[i]->show_info();
				flag=true;
			}
		}
		if(!flag)
		{
			cout<<"ְ��������"<<endl;
		}

	}
	system("pause");
    system("cls");
	
}
int WorkManager::isexist(int id)
{
	int index=-1;
	for(int i=0; i<this->num_emp;i++)
	{
		if(this->emp_array[i]->m_id==id)
		{
			index=i;
			break;
		}
	}
	return index;
}


void WorkManager::sort_emp()
{
	if (this->fileisempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < this->num_emp; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j <this->num_emp; j++)
			{
				if (select == 1) //����
				{
					if (this->emp_array[minOrMax]->m_id > this->emp_array[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else  //����
				{
					if (this->emp_array[minOrMax]->m_id < this->emp_array[j]->m_id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker * temp = this->emp_array[i];
				this->emp_array[i] = this->emp_array[minOrMax];
				this->emp_array[minOrMax] = temp;
			}

		}

		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->show_emp();
	}

}

void WorkManager::clean_file()
{	
	cout<<"ȷ�������"<<endl;
	cout<<"1.ȷ��   2.����"<<endl;
	int select;
	cin>>select;
	if(select==1)
	{
		ofstream ofs(fiename, ios::trunc);
		ofs.close();
		if (this->emp_array!=NULL)
		{
			for(int i = 0; i<this->num_emp;i++)
			{
				delete this->emp_array[i];
			}
		
			this->emp_array = 0;
			delete[] this->emp_array;
			this->emp_array = NULL;
			this->fileisempty = true;
		}
		cout<<"����ɹ�"<<endl;
	}
	system("pause");
	system("cls");
}
void WorkManager::exit_system()
{
    cout<<"��ӭ�´�ʹ�ã�"<<endl;
    system("pause");
    exit(0); 
}
int WorkManager::get_num_emp()
{
	int num=0;
	ifstream ifs;
	ifs.open(fiename,ios::in);
	int id;
	string name;
	int depnum;
	while(ifs>>id && ifs>>name && ifs>>depnum)
	{num++;}
	ifs.close();
	return num;
}

void WorkManager::emp_init()
{
	ifstream ifs;
	int id;
	string name;
	int depnum;
	ifs.open(fiename,ios::in);
	int index=0;
	while(ifs>>id && ifs>>name && ifs>>depnum)
	{
		Worker *work=NULL;
		if(depnum==1){work=new employee(id,name,depnum);}
		else if(depnum==2){work=new manager(id,name,depnum);}
		else if(depnum==3){work=new boss(id,name,depnum);}
		this->emp_array[index]=work;
		index++;
	}
	ifs.close();

}
void WorkManager::addemp()
{	
	cout<<"����Ҫ��ӵ�Ա����"<<endl;
	int addnum;
	cin>>addnum;
	if(addnum>0)
	{	
		int newsize = this->num_emp+addnum;
		Worker **newspace=new Worker*[newsize];
		if(this->emp_array!=NULL)
		{
			for (int i = 0; i < this->num_emp; i++)
			{
			    newspace[i]=this->emp_array[i];
			}

		}
		for (int i = 0; i < addnum; i++)
		{
			int ID;
			string name;
			int depnum;
			while(true)
			{
			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> ID;
			cin.ignore(1024,'\n');
			if (cin.fail())
			{
			
			    cin.clear();
			    cin.sync();
				cout <<"!!!��������ȷ�ı����ʽ!!!"<<endl;
			}
			else break;
			}

			
			while(true)
			{
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cin.ignore(1024,'\n');
			if (cin.fail())
			{
			
			    cin.clear();
			    cin.sync();
				cout <<"!!!��������ȷ��������ʽ!!!"<<endl;
			}
			else break;
			}


			while(true)
			{
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> depnum;
			cin.ignore(1024,'\n');
			if (cin.fail())
			{
			
			    cin.clear();
			    cin.sync();
				cout <<"!!!��������ȷ��ѡ����ʽ!!!"<<endl;
			}
			else
			{   
				if(depnum>=1 && depnum<=3){break;}
				else
				{
					cin.clear();
			    	cin.sync();
					cout <<"!!!��������ȷ��ѡ����ʽ!!!"<<endl;
				}
			} 
			}

			Worker * worker = NULL;

		    switch (depnum)
			{
			case 1:
				worker=new employee(ID,name,depnum);
				break;
			case 2:
				worker=new manager(ID,name,depnum);
				break;
			case 3:
				worker=new boss(ID,name,depnum);
				break;
			default:
				break;
			}
			newspace[this->num_emp+i]=worker;

		}
		delete[] this->emp_array;
		this->emp_array=newspace;
		this->num_emp=newsize;
		cout<<"�ɹ����"<<addnum<<"��Ա��"<<endl;
		this->fileisempty=false;
		this->save();
	}
	else
	{cout<<"��������!"<<endl;}
	system("pause");
    system("cls");
}
void WorkManager::save()
{
	fstream ofs;
	ofs.open(fiename,ios::out);
	for(int i=0; i<this->num_emp;i++)
	{
		ofs << this->emp_array[i]->m_id << " " 
			<< this->emp_array[i]->m_name << " " 
			<< this->emp_array[i]->m_Deptid << endl;
	}
	ofs.close();
}
WorkManager::~WorkManager()
{
	if (this->emp_array != NULL)
	{   
		for(int i= 0; i<this->num_emp; i++)
		{
			delete this->emp_array[i];
		}
		delete[] this->emp_array;
		this->emp_array=NULL;
		this->num_emp=0;
	}
}