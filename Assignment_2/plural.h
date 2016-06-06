//
//  plural.h
//  Assignment_2
//
//  Created by fengxinhe on 14-4-17.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef __Assignment_2__plural__
#define __Assignment_2__plural__

#include <iostream>

using namespace std;

class plural
{
    friend ostream&operator<<(ostream&,const plural&);
    friend istream&operator>>(istream&,plural&);
    
public:
    plural(double r=0,double i=0);
    
    void setRe(double r);
    void setIm(double i);
    
    double getRe() const;
    double getIm() const;
    
    void show() const;
   // plural(const char *str);
    
    const plural&operator=(const plural&);
    
    plural operator+(plural&);
    plural operator*(plural&);
    plural &operator++();
    plural operator++(int);
    plural operator+=(plural&);
    
    int operator==(const plural&) const;
    int operator!=(const plural&) const;
    
    ostream &print(ostream&)const;
private:
    double re;
    double im;
    
    
};



#endif /* defined(__Assignment_2__plural__) */
