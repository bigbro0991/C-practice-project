#include <iostream>
#define MAX 1000
    using namespace std;

void showmenu()
{
    string menu[7]={"Add  a Contact ","Show   Contact ","Delete Contact ","Search Contact ","Edit a Contact ","Empty  Contact ","Quit the System"};
    for(int i = 0; i < 6; i++)
    {
        cout<<"*****";
    }
    cout<<endl;
    for(int j = 0; j < 7; j++)
    {
        cout<<"***** "<<j+1<<". "<<menu[j]<<" *****"<<endl;
    }
    for(int i = 0; i < 6; i++)
    {
        cout<<"*****";
    }
    cout<<endl;
}

struct Contact
{
    string name;
    int gender;
    string number;
    int age;
    string address; 
};

struct Contactbook
{
    Contact contact_array[MAX];
    int contact_size;

};

void Add(Contactbook *Book)
{
  if (Book->contact_size == MAX)
  {
      cout<<"Contact is Full!"<<endl;
      return;
  }
  else
  {
      //name
      string name;
      cout<<"Please enter the name :"<<endl;
      char c;
      cin>>name;
      while((c=cin.get())!='\n')
      {
        name=name+c;
      }
      Book->contact_array[Book->contact_size].name=name;
      //sex
      int gender;
      cout<<"Please enter the gender :"<<endl;
      cout<<"1--Man,2--Woman"<<endl;
      while(true)
      { 
        
        cin>>gender;
        if (gender==1||gender==2)
        {
            Book->contact_array[Book->contact_size].gender=gender;
            break;
        }
        else
        {
            cout<<"Please enter the valid value !";
            cout<<"(1--Man,2--Woman)"<<endl;
        }
      }
      //age
      int age;
      cout<<"Please enter the age :"<<endl;
      while(true)
      { 
        
        cin>>age;
        if (age>0 && age<200)
        {
            Book->contact_array[Book->contact_size].age=age;
            break;
        }
        else
        {
            cout<<"Please enter the valid value !";
        }
      }
      //phone number
      string phone;
      cout<<"Please enter the phone number :"<<endl;
      cin>>phone;
      Book->contact_array[Book->contact_size].number=phone;
      //address
      string add;
      cout<<"Please enter the address :"<<endl;
      char r;
      cin>>add;
      while((r=cin.get())!='\n')
      {
        add=add+c;
      }
      Book->contact_array[Book->contact_size].address=add;
      //update size
      Book->contact_size++;
      cout<<"Added successfully"<<endl;
      system("pause");
      system("cls");
  }
}
void Show(Contactbook *Book)
{
  cout<<"Current number:"<<Book->contact_size<<endl;
  if(Book->contact_size==0)
  {
      cout<<"The Contacts is empty"<<endl;
  }
  else
  {
      for(int i=0; i<Book->contact_size; i++)
      {
          cout<<"Name: "<<Book->contact_array[i].name<<"\t";
          cout<<"Gender: "<<(Book->contact_array[i].gender==1?"Man":"Woman")<<"\t";
          cout<<"Age: "<<Book->contact_array[i].age<<"\t";
          cout<<"Phone Number: "<<Book->contact_array[i].number<<"\t";
          cout<<"Address: "<<Book->contact_array[i].address<<endl;
      }
  }
  system("pause");
  system("cls");
}
int isExist(Contactbook *Book,string name)
{
    for(int i=0; i<Book->contact_size; i++)
    {
        if(Book->contact_array[i].name==name)
            return i;
    }
    return -1;
}
void Delete(Contactbook *Book)
{
    string dname;
    cout<<"Please enter the name you want to delete :"<<endl;
    char c;
    cin>>dname;
      while((c=cin.get())!='\n')
      {
        dname=dname+c;
      }
    int ret=isExist(Book,dname);
    if (ret==-1)
    {
        cout<<"No such person"<<endl;
    }
    else
    {
        for(int i=ret; i<Book->contact_size-1; i++)
        {
            Book->contact_array[i]=Book->contact_array[i+1];
        }
        Book->contact_size--;
        cout<<"Delete Successfully!"<<endl;
    }
    system("pause");
    system("cls");
}
void Search(Contactbook *Book)
{
    string dname;
    cout<<"Please enter the name you want to search :"<<endl;
    char c;
    cin>>dname;
      while((c=cin.get())!='\n')
      {
        dname=dname+c;
      }
    int ret=isExist(Book,dname);
    if (ret==-1)
    {
        cout<<"No such person"<<endl;
    }
    else
    {
        cout<<"Name: "<<Book->contact_array[ret].name<<"\t";
        cout<<"Gender: "<<(Book->contact_array[ret].gender==1?"Man":"Woman")<<"\t";
        cout<<"Age: "<<Book->contact_array[ret].age<<"\t";
        cout<<"Phone Number: "<<Book->contact_array[ret].number<<"\t";
        cout<<"Address: "<<Book->contact_array[ret].address<<endl;
    }
    system("pause");
    system("cls");
}

void Edit(Contactbook *Book)
{
    string ename;
    cout<<"Please enter the name you want to search :"<<endl;
    char c;
    cin>>ename;
      while((c=cin.get())!='\n')
      {
        ename=ename+c;
      }
    int ret=isExist(Book,ename);
    if (ret==-1)
    {
        cout<<"No such person"<<endl;
    }
    else
    {
      //name
      string name;
      cout<<"Please enter the name :"<<endl;
      char c;
      cin>>name;
      while((c=cin.get())!='\n')
      {
        name=name+c;
      }
      Book->contact_array[ret].name=name;
      //sex
      int gender;
      cout<<"Please enter the gender :"<<endl;
      cout<<"1--Man,2--Woman"<<endl;
      while(true)
      { 
        
        cin>>gender;
        if (gender==1||gender==2)
        {
            Book->contact_array[ret].gender=gender;
            break;
        }
        else
        {
            cout<<"Please enter the valid value !";
            cout<<"(1--Man,2--Woman)"<<endl;
        }
      }
      //age
      int age;
      cout<<"Please enter the age :"<<endl;
      while(true)
      { 
        
        cin>>age;
        if (age>0 && age<200)
        {
            Book->contact_array[ret].age=age;
            break;
        }
        else
        {
            cout<<"Please enter the valid value !";
        }
      }
      //phone number
      string phone;
      cout<<"Please enter the phone number :"<<endl;
      cin>>phone;
      Book->contact_array[ret].number=phone;
      //address
      string add;
      cout<<"Please enter the address :"<<endl;
      char r;
      cin>>add;
      while((r=cin.get())!='\n')
      {
        add=add+c;
      }
      Book->contact_array[ret].address=add;
      //update size
      cout<<"Edit successfully"<<endl;
    }
    system("pause");
    system("cls");
}
void Empty(Contactbook *Book)
{
    Book->contact_size=0;
    cout<<"Clean up"<<endl;
    system("pause");
    system("cls");
}


int main()
{   

    Contactbook Book;
    Book.contact_size=0;
    
    while(true)
    {   
        showmenu();
        int op;
        cin>>op;
        switch(op)
        {
            case 1:
                Add(&Book);
                break;
            case 2:
                Show(&Book);
                break;
            case 3:
                Delete(&Book);
                break;
            case 4:
                Search(&Book);
                break;
            case 5:
                Edit(&Book);
                break;
            case 6:
                Empty(&Book);
                break;
            case 7:
                cout<<"See you !"<<endl;
                system("pause");
                return 0;
                break;
            default:
                cout<<"Please enter a right operate number !"<<endl;
                break;
        }
    
    }
    system("pause");
    return 0;
}