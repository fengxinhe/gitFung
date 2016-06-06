//
//  Shopping Card Data.h
//  Terminal Project
//
//  Created by fengxinhe on 14-5-12.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef __Terminal_Project__Shopping_Card_Data__
#define __Terminal_Project__Shopping_Card_Data__

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class Shopping_Card
{
public:
    long card_index;
    long card_balance;
public:
    Shopping_Card(long a,long b):card_index(a),card_balance(b){}
    ~Shopping_Card(){}
    long get_card_index()
    {
        return card_index;
    }
    long get_card_balance()
    {
        return card_balance;
    }
    
        
};



#endif /* defined(__Terminal_Project__Shopping_Card_Data__) */
