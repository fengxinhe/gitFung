//
//  Store.h
//  Terminal Project
//
//  Created by fengxinhe on 14-5-17.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef Terminal_Project_Store_h
#define Terminal_Project_Store_h
#include <vector>
#include <iostream>
#include "Item Data.h"

using namespace std;

//typedef struct tagStoreElement
//{
  //  Item *pitem;
    //long iNum;
//}storeElement,*pstoreElement;


class Store
{
private:
    vector<tagStoreElement> SEStore;
public:
    Store(){}
    ~Store(){}
    
public:
    long findGood(long);
    vector<pstoreElement>* getAllgood();
    pstoreElement getGood(long);
    void basket_print();
    bool add_good(Item*,long);
    
};

#endif
