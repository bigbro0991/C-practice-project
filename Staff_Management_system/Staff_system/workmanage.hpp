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
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
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
		cout<<"记录为空"<<endl;
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
		cout<<"记录为空"<<endl;
		return;
	}
	int Id;
	cout<<"请输入要删除的员工编号:"<<endl;
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
		cout<<"删除成功"<<endl;
	}
	else
	{
		cout<<"删除失败，职工不存在"<<endl;
	}
	system("pause");
	system("cls");
	
}

void WorkManager::mod_emp()
{
	if(this->fileisempty)
	{
		cout<<"记录为空"<<endl;
		return;
	}
	int Id;
	cout<<"请输入要修改的员工编号:"<<endl;
	cin>>Id;
	int ret=this->isexist(Id);
	if(ret!=-1)
	{

		cout << "查询到" <<emp_array[ret]->m_id<< "号职工" << endl;
		emp_array[ret]->show_info();
		delete this->emp_array[ret];
		int ID;
		string name;
		int depnum;
		

		cout << "请输入新的员工号"<<endl;
		cin >> ID;


		cout << "请输入新的职工姓名"<<endl;
		cin >> name;


		cout << "请选择该职工的岗位：" << endl;
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
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
		cout<<"修改成功"<<endl;
	}
	else
	{
		cout<<"修改失败，职工不存在"<<endl;
	}
	system("pause");
	system("cls");
}


void WorkManager::find_emp()
{
	if(this->fileisempty)
	{
		cout<<"记录为空"<<endl;
		system("pause");
    	system("cls");
		return;
	}
	int select;
	cout<<"请选择查找方式：1. 按员工编号查找 2. 按姓名查找"<<endl;
	cin>>select;
	if(select==1)
	{
		int Id;
		cout<<"请输入要修改的员工编号:"<<endl;
		cin>>Id;
		int ret=this->isexist(Id);
		if(ret!=-1)
		{
			emp_array[ret]->show_info();
		}
		else
	    {
		cout<<"职工不存在"<<endl;
	    }
	}
	else if(select==2)
	{
	    string Name;
		bool flag=false;
		cout<<"请输入要修改的员工姓名:"<<endl;
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
			cout<<"职工不存在"<<endl;
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
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;


		for (int i = 0; i < this->num_emp; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j <this->num_emp; j++)
			{
				if (select == 1) //升序
				{
					if (this->emp_array[minOrMax]->m_id > this->emp_array[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else  //降序
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

		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->show_emp();
	}

}

void WorkManager::clean_file()
{	
	cout<<"确定清空吗？"<<endl;
	cout<<"1.确定   2.返回"<<endl;
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
		cout<<"清理成功"<<endl;
	}
	system("pause");
	system("cls");
}
void WorkManager::exit_system()
{
    cout<<"欢迎下次使用！"<<endl;
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
	cout<<"输入要添加的员工数"<<endl;
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
			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> ID;
			cin.ignore(1024,'\n');
			if (cin.fail())
			{
			
			    cin.clear();
			    cin.sync();
				cout <<"!!!请输入正确的编号形式!!!"<<endl;
			}
			else break;
			}

			
			while(true)
			{
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			cin.ignore(1024,'\n');
			if (cin.fail())
			{
			
			    cin.clear();
			    cin.sync();
				cout <<"!!!请输入正确的姓名形式!!!"<<endl;
			}
			else break;
			}


			while(true)
			{
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> depnum;
			cin.ignore(1024,'\n');
			if (cin.fail())
			{
			
			    cin.clear();
			    cin.sync();
				cout <<"!!!请输入正确的选择形式!!!"<<endl;
			}
			else
			{   
				if(depnum>=1 && depnum<=3){break;}
				else
				{
					cin.clear();
			    	cin.sync();
					cout <<"!!!请输入正确的选择形式!!!"<<endl;
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
		cout<<"成功添加"<<addnum<<"名员工"<<endl;
		this->fileisempty=false;
		this->save();
	}
	else
	{cout<<"输入有误!"<<endl;}
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