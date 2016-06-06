//
//  main.cpp
//  Terminal Project
//
//  Created by fengxinhe on 14-5-12.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Counter.h"
#include "Item Data.h"
#include "Member Data.h"
#include "Shopping Card Data.h"
#include "Store.h"
#include "Store.cpp"


void remind()
{
    cout<<endl;
    cout<<"welcome to the supermarket"<<endl;
    cout<<"please input the data as hint"<<endl;
    cout<<"please input -1 to finish settlement"<<endl;
    cout<<endl;
    cout<<endl;
}


int main(int argc, const char * argv[])
{
    Store *newStore;
    newStore=prepareStore();
    Store *pBasket=new Store();
    Counter Counter(pBasket);
    Item *pMyGood;
    double dcash=0.0;
    remind();
    long number,iidex=0;
    while (iidex!=-1) {
        cout<<"please input the code of the good"<<endl;
        cin>>iidex;
        pstoreElement pse=newStore->getGood(iidex);
       // if (pse==NULL) {
         //   cout<<"sorry,we do not have such good with input code"<<iidex<<endl;
           // continue;
        //}
        cout<<"please input the quantity of good you want"<<endl;
        cin>>number;
        if (number<NULL) {
            cout<<"input the wrong number,the number should > 0"<<endl;
            continue;
        }
        long tnumber=newStore->findGood(iidex);
        if (tnumber<=0) {
            cout<<"sorry,the good has sale out"<<endl;
        }
        else{
            if (number>tnumber) {
                cout<<"sorry,our supermarket has goods"<<pse->pitem->get_item_name()<<"only"<<tnumber<<"please buy the quantities "<<tnumber<<"just now"<<endl;
                pMyGood=pse->pitem->clone();
                pBasket->add_good(pMyGood, tnumber);
                pse->iNum=0;
            }
            else
            {
                cout<<"you have bought"<<pse->pitem->get_item_name()<<' '<<number<<endl;
                pMyGood=pse->pitem->clone();
                pBasket->add_good(pMyGood, number);
                pse->iNum=tnumber-number;
            }
        }
    }
    pBasket->basket_print();
    cout<<"total :"<<' '<<Counter.Bill()<<"RMB"<<endl;
    
    
    

    
    
    
    
    
    
    
    
    return 0;
}












