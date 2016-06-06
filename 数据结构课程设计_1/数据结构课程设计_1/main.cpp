//
//  main.cpp
//  数据结构课程设计_1
//
//  Created by fengxinhe on 14-9-22.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#include <iostream>
#include "Header.h"

using namespace std;

int main(int argc, const char * argv[])
{

    int num;
    cout<<"首先请建立考生信息系统"<<endl;
    cout<<"请输入考生人数：";
    cin>>num;
    cout<<endl;
    linklist X;
    X.creat();
    cout<<"请依次输入考生的考号，姓名，年龄及报考类别！"<<endl;
    while (num--) {
        X.insert_one();
    }
    X.output();
             //linklist X;
             cout<<"欢迎来到我的学生信息管理系统，请输入相应序号进行操作："<<endl
                 <<"1为插入 2为删除"<<endl
                 <<"3为查找 4为修改"<<endl
                 <<"5为统计 0为取消操作";
             //X.creat();
    
             while (true){
                     int choise;
                     cout<<"请输入操作序号： "<<endl;
                     cin>>choise;
                     switch (choise)
                     {
                         case 1:
                             X.setmore();
                             X.output();
                             break;
                         case 2:{
                                 //cout<<"请输入要删除的考生的考号： ";
                                 X.delete_data();
                             X.output();
                                 break;
                             }
                        case 3:
                             X.check();
                             X.output();
                             break;
                         case 4:
                             X.setdata();
                             X.output();
                             break;
                         case 5:
                             X.setdata();break;
                        case 0:
                             continue;
                         default:
                             cout<<"对不起，有关功能正在开发！^-^"<<endl;break;
                         }
                     if (!choise) break;
                 }
    
             return 0;
         

}

