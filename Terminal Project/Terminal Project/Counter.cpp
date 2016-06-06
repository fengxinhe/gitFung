//
//  Counter.cpp
//  Terminal Project
//
//  Created by fengxinhe on 14-5-12.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#include "Counter.h"



Counter::Counter(Store *pBasket)
{
    aBasket=pBasket;
}

double Counter::Bill()
{
    double total=0.0;
    vector<pstoreElement>*pvse=aBasket->getAllgood();
    for (int i=0; i<(*pvse).size(); i++) {
        pstoreElement pse=(*pvse)[i];
        total+=pse->pitem->get_item_price()*pse->iNum;
    }
    return total;
}

double Counter::Change(double cash)
{
    double total=Bill();
    double check=cash-total;
    return check;
}
