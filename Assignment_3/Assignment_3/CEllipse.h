//
//  CEllipse.h
//  Assignment_3
//
//  Created by fengxinhe on 14-5-5.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//  1352959_冯馨荷_作业3_main.cpp


#ifndef __Assignment_3__CEllipse__
#define __Assignment_3__CEllipse__

#include <iostream>
#include "CShape.h"

class CEllipse : public CShape
{
private:
    float a,b;
public:
    virtual CEllipse*clone()const
    {
        return new CEllipse(*this);
    }
    CEllipse()=default;
    CEllipse(float aa,float bb){a=aa;b=bb;}
    void set(float aa,float bb){a=aa,b=bb;}
    string who_am_i()
    {
        return("ellipse");
    }
    float getCircumference()
    {
        return (2*b*3.14+4*(a-b));
    }
    float getArea()
    {
        return(3.14*a*b);
    }
    bool checkIntegrity()
    {
        if(a>0&&a<1024&&b>0&&b<1024) return true;
        else return false;
    }
    void print()
    {
        ofstream ofile("/Users/dingpeien/Desktop/out1.txt",ios::app);
        ofile<<who_am_i()<<' '<<"长轴为"<<a<<"短轴为"<<b<<"的椭圆形，周长为"<<getCircumference()<<"，面积为"<<getArea()<<endl;
    }
};




#endif /* defined(__Assignment_3__CEllipse__) */
