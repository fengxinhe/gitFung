//
//  Item Data.h
//  Terminal Project
//
//  Created by fengxinhe on 14-5-12.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef __Terminal_Project__Item_Data__
#define __Terminal_Project__Item_Data__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>


using namespace std;


class Item
{
public:
    long item_index;
    string item_name;
    string item_parea;
    double item_price;
    long item_num;
    
public:
    Item()=default;
    Item(long a,string b,string c,double d):
    item_index(a),item_name(b),item_parea(c),item_price(d){}
    Item(long a,long b)
    {
        item_index=a;
        item_num=b;
    }
    ~Item(){}
    long get_item_index()
    {
        return item_index;
    }
    string get_item_name()
    {
        return item_name;
    }
    string get_item_parea()
    {
        return item_parea;
    }
    double get_item_price()
    {
        return item_price;
    }
   Item *clone()
    {
        return new Item(item_index,item_name,item_parea,item_price);

    }
    
};

class tagStoreElement
{
    Item *pitem;
    long iNum;
};
tagStoreElement storeElement;
tagStoreElement *pstoreElement;





#endif /* defined(__Terminal_Project__Item_Data__) */
