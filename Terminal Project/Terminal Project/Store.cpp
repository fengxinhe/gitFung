//
//  Store.cpp
//  Terminal Project
//
//  Created by fengxinhe on 14-5-14.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#include "Store.h"
#include <iomanip>


bool Store::add_good(Item* pitem, long iNum)
{
    //int size=SEStore.size();
    bool exit=false;
    if (!exit) {
        pstoreElement p=new storeElement;
        p->pitem=pitem;
        p->iNum=iNum;
        SEStore.push_back(p);
    }
    for (int x=0; x<SEStore.size(); x++) {
        pstoreElement pse=SEStore[x];
        if (pse->pitem!=NULL&&pse->pitem->get_item_index()==pitem->get_item_index()) {
            exit=true;
            pse->iNum+=iNum;
        }
    }
    return exit;
}

long Store::findGood(long index)
{
    for (int i=0; i<SEStore.size(); i++) {
        pstoreElement pse=SEStore[i];
        if (pse->pitem!=NULL&&pse->pitem->get_item_index()==index) {
            return pse->iNum;
        }
    }
        return NULL;
}

vector<pstoreElement>* Store::getAllgood()
{
    return &SEStore;
}

pstoreElement Store::getGood(long index)
{
    for (int i=0; i<SEStore.size(); i++) {
        pstoreElement pse=SEStore[i];
        if (pse->pitem!=NULL&&pse->pitem->get_item_index()==index) {
            return pse;
        }
    }
    return NULL;
}

void Store::basket_print()
{
    cout<<"good name"<<setw(15)<<"good produce area"<<setw(15)<<"good price"<<endl;
    for (int i=0; i<SEStore.size(); i++) {
       //pstoreElement pse=SEStore[i];
        cout<<setw(5);
        cout<<SEStore[i]->pitem->get_item_name();
        cout<<setw(15);
        cout<<SEStore[i]->pitem->get_item_parea();
        cout<<setw(15)<<setiosflags(ios::fixed)<<setprecision(2)<<SEStore[i]->pitem->get_item_price()<<endl;
    }
    
}

Store* prepareStore()
{
    ifstream ifile_1("/Users/dingpeien/Desktop/t_in_item.txt");
    Store*newStore=new Store();
    long code;
    string name;
    string area;
    double price;
    while (ifile_1) {
        ifile_1>>code>>name>>area>>price;
        Item *pitem=new Item(code,name,area,price);
        newStore->add_good(pitem, 1000);
    }
    return newStore;
}




