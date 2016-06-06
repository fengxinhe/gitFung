//
//  main.cpp
//  Assignment_3
//
//  Created by fengxinhe on 14-5-5.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//  1352959_冯馨荷_作业3_main.cpp

#include <iostream>
#include "CShape.h"
#include "CRectangle.h"
#include "CEllipse.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CTriangle.h"
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

int main(int argc, const char * argv[])
{
   
    int cc=0,ce=0,csq=0,cre=0,ctr=0;
    ifstream ifile("/Users/dingpeien/Desktop/in.txt");
    ofstream ofile("/Users/dingpeien/Desktop/out1.txt");
    vector<CCircle>cir;
    CCircle elem_cir;
    vector<CEllipse>ell;
    CEllipse elem_ell;
    vector<CSquare>squ;
    CSquare elem_squ;
    vector<CRectangle>rec;
    CRectangle elem_rec;
    vector<CTriangle>tri;
    CTriangle elem_tri;
    
    int num,elem_num;
    ifile>>num;
    CShape *Shape[num];
    vector<int>flag;
    
    
    
    if (ifile) {
        
        for (int x=0; x<num; x++) {
            ifile>>elem_num;
    
            flag.push_back(elem_num);
            if(elem_num==1){
                float radius;
                ifile>>radius;
                CCircle elem_cir(radius);
                cir.push_back(elem_cir);
                Shape[x]=&cir[cc];
                ++cc;
                
            }
            
            if(elem_num==2){
                float lo,so;
                ifile>>lo>>so;
                CEllipse elem_ell(lo, so);
                ell.push_back(elem_ell);
                Shape[x]=&ell[ce];
                ++ce;
            }
            
            if(elem_num==3){
                float l,s;
                ifile>>l>>s;
                CRectangle elem_rec(l,s);
                rec.push_back(elem_rec);
                Shape[x]=&rec[cre];
                ++cre;
            }
            if(elem_num==4){
                float a,b,c;
                ifile>>a>>b>>c;
                CTriangle elem_tri(a,b,c);
                tri.push_back(elem_tri);
                Shape[x]=&tri[ctr];
                ++ctr;
            }
            if(elem_num==5){
                float side;
                ifile>>side;
                CSquare elem_squ(side);
                squ.push_back(elem_squ);
                Shape[x]=&squ[csq];
                ++csq;
            }
        }
    }
    
    
    int a=0,b=0,c=0,d=0,e=0;
   
    for (int z=0; z<flag.size(); ++z) {
        
            if (flag[z]==1) {
                CShape *ps=&cir[a];
                if (typeid(*ps)==typeid(CCircle))
                {
                    ofile<<"function clone in class CCirle is called"<<endl;
                    cir[a].clone();
                    ++a;
                }
                    else ofile<<"can not call function clone in class CCircle"<<endl;
            }
            else if (flag[z]==2) {
                CShape *ps=&ell[b];
                
                if (typeid(*ps)==typeid(CEllipse))
                {
                    ofile<<"function clone in class CEllipse is called"<<endl;
                    ell[b].clone();
                    ++b;
                }
                else ofile<<"can not call function clone in class CEllipse"<<endl;
            }
            else if (flag[z]==3) {
                CShape *ps=&rec[c];
                
                if (typeid(*ps)==typeid(CRectangle))
                {
                    ofile<<"function clone in class CRectangle is called"<<endl;
                    rec[c].clone();
                    ++c;
                }
                else ofile<<"can not call function clone in class CRetangle"<<endl;
            }
            else if (flag[z]==4) {
                    CShape *ps=&tri[d];
                
                    if (typeid(*ps)==typeid(CTriangle))
                    {
                        ofile<<"function clone in class CTriangle is called"<<endl;
                        tri[d].clone();
                        ++d;
                    }
                    else ofile<<"can not call function clone in class CTriangle"<<endl;
                }
           else if (flag[z]==5) {
                CShape *ps=squ[e].clone();
               
                if (typeid(*ps)==typeid(CSquare))
                {
                    ofile<<"function clone in class CSquare is called"<<endl;
                    squ[e].clone();
                    ++e;
                }
                else ofile<<"can not call function clone in class CSquare"<<endl;
            }
        
        
    }
   
    
    vector<CShape*> cShape(Shape,Shape+num);
    cout<<cShape.size()<<endl;
    vector<CShape*>::const_iterator iter=cShape.begin(),end_it=cShape.end();
    for ( ;iter!=end_it; iter++) {
        (*iter)->print();
    }

    return 0;
}

