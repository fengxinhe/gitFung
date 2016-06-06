//
//  CSquare.h
//  Assignment_3
//
//  Created by fengxinhe on 14-5-5.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//  1352959_冯馨荷_作业3_main.cpp


#ifndef __Assignment_3__CSquare__
#define __Assignment_3__CSquare__

#include <iostream>
#include "CShape.h"


class CSquare:public CShape
{
private:
    float a;
public:
    virtual CSquare*clone()const
    {
        return new CSquare(*this);
    }
    CSquare()=default;
    CSquare(float aa){a=aa;}
    void set(float aa){a=aa;}
    string who_am_i()
    {
        return("square");
    }
    float getCircumference()
    {
        return (a*4);
    }
    float getArea()
    {
        return(a*a);
    }
    bool checkIntegrity()
    {
        if(a>0&&a<1024) return true;
        else return false;
    }
    void print()
    {
        ofstream ofile("/Users/dingpeien/Desktop/out1.txt",ios::app);
        ofile<<who_am_i()<<' '<<"边长为"<<a<<"的正方形，周长为"<<getCircumference()<<"，面积为"<<getArea()<<endl;
    }
   
};


#endif /* defined(__Assignment_3__CSquare__) */
