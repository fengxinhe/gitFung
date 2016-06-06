//
//  CShape.h
//  Assignment_3
//
//  Created by fengxinhe on 14-5-5.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//  1352959_冯馨荷_作业3_main.cpp


#ifndef __Assignment_3__CShape__
#define __Assignment_3__CShape__

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class CShape
{
public:
    virtual CShape* clone() const=0;
   // {
     //   return new CShape(*this);
    //}
    
    virtual string who_am_i()=0;
    virtual bool checkIntegrity()=0;
    virtual float getCircumference()=0;
    virtual float getArea()=0;
    virtual void print()=0;
    
};





#endif /* defined(__Assignment_3__CShape__) */
