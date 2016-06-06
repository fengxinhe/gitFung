//
//  Counter.h
//  Terminal Project
//
//  Created by fengxinhe on 14-5-12.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef __Terminal_Project__Counter__
#define __Terminal_Project__Counter__

#include <iostream>
#include <vector>
#include "Store.h"


using namespace std;

class Counter
{
    Store *aBasket;
    
public:
    Counter(Store *pBasket);
    virtual ~Counter(){}
    double Bill();
    double Change(double dcash);
    double get_cash();
    
    
    
};


#endif /* defined(__Terminal_Project__Counter__) */
