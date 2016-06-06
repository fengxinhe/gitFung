//
//  main.cpp
//  函数重载
//
//  Created by fengxinhe on 14-3-17.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(vector<int>&,const string &,ostream &os =cout);

bool calc(vector<int>& ,int);


int main(int argc, const char * argv[])
{
    const string title("pentagonal numeic series");
    vector<int> pnum;
    
    int pos;
    int a=3;
    if (a>0) {
        
        cout<<"please input how many numbers youwant"<<endl;
        cin>>pos;
        if(calc(pnum, pos))
            display(pnum, title);
        a=a-7;
    }
    else {
        cout<<"thank you"<<endl;
    
    }
    
    
       return 0;
}

bool calc(vector<int>&vec,int pos)
{
    if (pos<=0||pos>=128) {
        cerr<<"sorry,invalid position: "<<pos<<endl;
        return false;
    }
    int i;
    for (i=vec.size()+1; i<=pos;++i )
     {
        vec.push_back((i*(3*i-1)/2));
    }
    
    return true;
}

void display(vector<int>&a,const string &b,ostream &os)
{
    os<<'\n'<<b<<"\n\t";
    for (int ix=0;ix<=a.size()+1;++ix )
    {
        os<<a[ix]<<' ';
        os<<endl;
    }
    
}


