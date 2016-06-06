//
//  Header.h
//  数据结构课程设计_1
//
//  Created by fengxinhe on 14-9-22.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef _________1_Header_h
#define _________1_Header_h

#include<iostream>
#include <string>
#include<iomanip>
//#define NULL 0

 using namespace std;

 class StudentData{
     public:
     string name;
     long stucode;
     string sex;
     string job;
     int age;
       //  int math,english,lang,chemistry,biology,physics,number;
     
     StudentData *next;
     StudentData *pre;
         void insertdate(){
               //  cin>>lang>>math>>english>>physics>>chemistry>>biology;
             cin>>stucode>>name>>sex>>age>>job;
             }
     void setStucode(){cin>>stucode;}
     void setName(){cin>>name;}
     void setSex(){cin>>sex;}
     void setAge(){cin>>age;}
     void setJob(){cin>>job;}
      // void setlang(){cin >> lang;}
       //  void setmath(){cin >> math;}
       //  void setenglish(){cin >> english;}
       //  void setphysics(){cin >> physics;}
       //  void setchemistry(){cin >> chemistry;}
       //  void setbiology(){cin >> biology;}
     };

 class linklist{
     public:
         StudentData *head,*present;
         void insert_one();
         void delete_data();
         void setdata();
         bool check();
         void creat();
         void output();
         void setmore();
     StudentData *locate(int);
     };

 void linklist::output(){
         cout<<"考号   姓名    性别   年龄   报考类别"<<endl;
         present = head;
         while(present!= NULL){
                 cout<<present->stucode<<setw(12)<<present->name<<setw(8)<<present->sex<<setw(8)<<present->age<<setw(8)<<present->job;
             cout<<endl;
                 present = present->next;
             }
     }

 void linklist::creat(){
         present = new StudentData;
         head = present;
         present->next = NULL;
         present->pre = NULL;
     }

 void linklist::insert_one(){
         present = new StudentData;
         head->pre = present;
         present->next = head;
         head = present;
         present->pre = NULL;
         //cout<<"请输入学生姓名: ";
         //cin>>present->name;
         //cout<<"请输入学号：";
         //cin>>present->stucode;
     //cin>>present->stucode>>present->name>>present->sex>>present->age>>present->job;
     //cout<<"请一次输入code name sex age job："<<endl;   //插入成绩
     
        present->insertdate();        //输入成绩
     }

 void linklist::delete_data(){
         //string studentname;
        // int sigh = 0;
         cout<<"请输入要删除的学生考号： ";
         if (check()) {
                 cout<<"删除数据成功！"<<endl;
                 delete present;
             }
         else cout<<"删除失败。"<<endl;
     }

 bool linklist::check(){
         present = head;
         long code;
         cin>>code;
         while (present->next != NULL)
             {
                     if (code == present->stucode){
                         cout<<"    考号   姓名    性别   年龄   报考类别"<<endl;
                         cout<<present->stucode<<setw(12)<<present->name<<setw(8)<<present->sex<<setw(8)<<present->age<<setw(8)<<present->job<<endl;
                         
                         
                             return true;
                         }
                     else {
                             present = present->next;
                             continue;
                         }
                 }
         cout<<"查无此人！"<<endl;
         return false;
     }

 void linklist::setdata(){
         string the_name;
         int subject;
         cout<<"请输入学生考号: ";
         if (check()){
                 while(1){
                         cout<<"1.考号    2.姓名"<<endl
                             <<"3.性别    4.年龄"<<endl
                             <<"5.报考类别"<<endl;
                         cout<<"请输入需要修改的科目编号: ";
                         cin >> subject;
                         switch (subject)
                         {
                             case 1:present->setStucode();break;
                             case 2:present->setName();break;
                             case 3:present->setSex();break;
                             case 4:present->setAge();break;
                             case 5:present->setJob();break;
                            
                             default: {
                                     cout<<"回到上级菜单。"<<endl;
                                     return ;
                                 }
                             }
                         cout<<"修改成功！"<<endl;
                     }
             }
     }
StudentData*linklist::locate(int i){
    if (i<0) return NULL;
    StudentData*p=head; int k=0;
    while (p!=NULL&&k<i) {
        p=p->next;
        k++;
    }
    return p;
}

 void linklist::setmore(){
         cout<<"请输入要插入的考生位置： ";
         int n;
         cin>>n;
     present=new StudentData;
     cout<<"请一次输入code name sex age job："<<endl;   //插入成绩
    // present->insertdate();        //输入成绩
     cin>>present->stucode>>present->name>>present->sex>>present->age>>present->job;
     
     StudentData*temp=locate(n);
     if(temp==NULL) cerr<<"找不到指定位置！"<<endl;
     present->next=temp->next;
     temp->next=present;
     
     }
#endif
