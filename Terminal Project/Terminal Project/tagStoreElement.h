//
//  tagStoreElement.h
//  Terminal Project
//
//  Created by fengxinhe on 14-5-15.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef Terminal_Project_tagStoreElement_h
#define Terminal_Project_tagStoreElement_h
#include"Item Data.h"
#include <iostream>


typedef struct tagStoreElement
{
    Item *pitem;
    long iNum;
}storeElement,*pstoreElement;


#endif
