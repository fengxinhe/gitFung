//
//  CTriangle.h
//  Assignment_3
//
//  Created by fengxinhe on 14-5-5.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//  1352959_冯馨荷_作业3_main.cpp


#ifndef __Assignment_3__CTriangle__
#define __Assignment_3__CTriangle__

#include <iostream>
#include <math.h>
#include "CShape.h"

class CTriangle:public CShape
{
private:
    float a,b,c;
public:
    virtual CTriangle*clone()const
    {
        return new CTriangle(*this);
    }
    CTriangle()=default;
   
    CTriangle(float aa,float bb,float cc){a=aa;b=bb;c=cc;}
    void set(float aa,float bb,float cc){a=aa;b=bb;c=cc;}
    string who_am_i()
    {
        return("triangle");
    }
    float getCircumference()
    {
        return (a+b+c);
    }
    float getArea()
    {
        float p=(a+b+c)/2;
        return(pow(p*(p-c)*(p-b)*(p-a),0.5));
    }
    bool checkIntegrity()
    {
        if(a>0&&a<1024&&b>0&&b<1024&&c>0&&c<1024) return true;
        else return false;
    }
    bool IsTriangle()
    {
        if(a+b>c&&a+c>b&&b+c>a) return true;
        else return false;
    }
   void print()
    {
        ofstream ofile("/Users/dingpeien/Desktop/out1.txt",ios::app);
        ofile<<who_am_i()<<' '<<"边长分别为"<<a<<","<<b<<","<<c<<"的三角形周长为"<<getCircumference()<<"，面积为"<<getArea()<<endl;
    }
};

#endif /* defined(__Assignment_3__CTriangle__) */
