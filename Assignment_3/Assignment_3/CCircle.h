//
//  CCircle.h
//  Assignment_3
//
//  Created by fengxinhe on 14-5-5.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//  1352959_冯馨荷_作业3_main.cpp


#ifndef __Assignment_3__CCircle__
#define __Assignment_3__CCircle__

#include <iostream>
#include "CShape.h"


class CCircle:public CShape
{
private:
    float a;
public:
    virtual CCircle*clone()const
    {
        return new CCircle(*this);
    }
    CCircle()=default;
    
    CCircle(float aa){a=aa;}
    void set(float aa){a=aa;}
    string who_am_i()
    {
        return("circle");
    }
    bool checkIntegrity()
    {
        if(a>0&&a<1024) return true;
        else return false;
    }
    float getCircumference()
    {
        return (2*3.14*a);
    }
    float getArea()
    {
        return(a*a*3.14);
    }
    
    void print()
    {
        ofstream ofile("/Users/dingpeien/Desktop/out1.txt",ios::app);
        
        ofile<<who_am_i()<<' '<<"半径为"<<a<<"的圆形，周长为"<<getCircumference()<<"，面积为"<<getArea()<<endl;
        
    }
    
};
//inline ostream&
//operator<<( ostream& os,CCircle &c  )
//{
  // return  c.print(os);
//}


#endif /* defined(__Assignment_3__CCircle__) */
