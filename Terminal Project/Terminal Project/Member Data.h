//
//  Member Data.h
//  Terminal Project
//
//  Created by fengxinhe on 14-5-12.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef __Terminal_Project__Member_Data__
#define __Terminal_Project__Member_Data__

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class Member
{
public:
    long member_index;
    string member_name;
    string member_gender;
    long member_phone;
    string member_rank;
    long member_points;
public:
    Member(long a,string b,string c,long d,string e,long f):
    member_index(a),member_name(b),member_gender(c),member_phone(d),member_rank(e),member_points(f){}
    ~Member(){}
    long get_member_index()
    {
        return member_index;
    }
    string get_member_name()
    {
        return member_name;
    }
    string get_member_gender()
    {
        return member_gender;
    }
    long get_member_phone()
    {
        return member_phone;
    }
    string get_member_rank()
    {
        return member_rank;
    }
    long get_member_points()
    {
        return member_points;
    }
    
    map<Member, int> member_data;
    void member_list()
    {
        ifstream ifile_2("");
        long a;
        string b;
        string c;
        long d;
        string e;
        long f ;
        while (ifile_2) {
            ifile_2>>a>>b>>c>>d>>e>>f;
            Member mem(a, b, c, d, e, f);
            member_data[mem]++;
        }
    }
    
    
    
    
};





#endif /* defined(__Terminal_Project__Member_Data__) */
