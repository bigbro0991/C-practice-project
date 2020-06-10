#include<iostream>
#include<string>
#include"Worker.h"
#include"emplyee.hpp"
#include"manager.hpp"
#include"boss.hpp"
#include"workmanage.hpp"
using namespace std;


int main()
{
    WorkManager wm;
    int choice=0;
    
    while(true)
    {
        wm.show_menu();
        cout<<"请输入您的选择：";
        cin>>choice;

        switch(choice)
        {
            case 0:
                wm.exit_system();
                break;
            case 1:
                wm.addemp();
                break;
            case 2:
                wm.show_emp();
                break;
            case 3:
                wm.del_emp();
                break;
            
            case 4:
                wm.mod_emp();
                break;
            case 5:
                wm.find_emp();
                break;
            case 6:
                wm.sort_emp();
                break;
            case 7:
                wm.clean_file();
                break;   
            default:
                cout<<"请输入正确选项。"<<endl;
                system("pause");
                system("cls");
                break;

        }
    }
    system("pause");
    system("cls");
    return 0;
}