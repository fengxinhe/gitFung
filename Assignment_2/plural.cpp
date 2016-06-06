//
//  plural.cpp
//  Assignment_2
//
//  Created by fengxinhe on 14-4-17.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#include "plural.h"

#include <fstream>

using namespace std;

plural::plural(double r,double i)
{
    re=r;
    im=i;
}

void plural::setRe(double r)
{
    re = r;
}

void plural::setIm(double i)
{
    im = i;
}

double plural::getRe() const
{
    return re;
}

double plural::getIm() const
{
    return im;
}

const plural&plural::operator=(const plural&t)
{
    
        re=t.re;
        im=t.im;
    
    return *this;
}

plural plural::operator+(plural&z)
{
    plural t(0,0);
    t.re=re+z.re;
    t.im=im+z.im;
    return t;
}

plural plural::operator+=(plural &z)
{
    re=re+z.re;
    im=im+z.im;
    return *this;
}

plural plural::operator*(plural&z)
{
    plural t(0,0);
    t.re=re*z.re-im*z.im;
    t.im=re*z.im+im*z.re;
    
    return t;
}

plural&plural::operator++()
{
    re=re+1;
    im=im+1;
    return *this;
}

plural plural::operator++(int)
{
    re=re+1;
    im=im+1;
    return *this;
}

int plural::operator==(const plural&z) const
{
        return (re==z.re&&im==z.im);
}

int plural::operator!=(const plural&z)const
{
    return (re!=z.re||im!=z.im);
}

ostream&operator<<(ostream&os,const plural&z)
{
    return z.print(os);
}

ostream &plural::print(ostream&output) const
{
    if(im==0)
        output<<re;
    if(re==0&&im!=0&&im!=1&&im!=-1)
        output<<im<<"i";
    if(re==0&&im==1)
        output<<"i";
    if(re==0&&im==-1)
        output<<"-i";
    if(re!=0&&im>0&&im!=1)
        output<<re<<"+"<<im<<"i";
    if(re!=0&&im==1)
        output<<re<<"+"<<"1i";
    if(re!=0&&im<0&&im!=-1)
        output<<re<<im<<"i";
    if(re!=0&&im==-1)
        output<<re<<"-i";
    return output;
}

istream &operator>>(istream &input,plural&z)
{
   /* //std::cout << "请输入实数部分：" ;
    input >> z.re;
    if(input)
    {
        //std::cout << "请输入虚数部分：" ;
        input >> z.im;
        if(input)
        {
            return input;
        }
        else
        {
            z = plural(0.0);
        }
    }
    else
    {
        z = plural(0.0);
    }*/
    input>>z.re>>z.im;
    return input;
}



