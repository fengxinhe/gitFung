//
//  CRectangle.h
//  Assignment_3
//
//  Created by fengxinhe on 14-5-5.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//  1352959_冯馨荷_作业3_main.cpp


#ifndef __Assignment_3__CRectangle__
#define __Assignment_3__CRectangle__

#include <iostream>
#include "CShape.h"

class CRectangle:public CShape
{
private:
    float a,b;
public:
    virtual CRectangle*clone()const
    {
        return new CRectangle(*this);
    }
    CRectangle()=default;
    CRectangle(float aa,float bb){a=aa;b=bb;}
    void set(float aa,float bb){a=aa;b=bb;}
    string who_am_i()
    {
        return("rectangle");
    }
    float getCircumference()
    {
        return (a*2+b*2);
    }
    float getArea()
    {
        return(a*b);
    }
    bool checkIntegrity()
    {
        if(a>0&&a<1024&&b>0&&b<1024) return true;
        else return false;
    }
   void print()
    {
        ofstream ofile("/Users/dingpeien/Desktop/out1.txt",ios::app);
        ofile<<who_am_i()<<' '<<"长为"<<a<<"宽为"<<b<<"的长方形，周长为"<<getCircumference()<<"，面积为"<<getArea()<<endl;
    }
};



#endif /* defined(__Assignment_3__CRectangle__) */
