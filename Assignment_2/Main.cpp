//
//  Main.cpp
//  Assignment_2
//
//  Created by fengxinhe on 14-4-15.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#import "Matrix.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

template <typename t>
void input_mat_elem(const vector<t>&,Matrix<t>&,int &,int &);


int main(int argc, const char * argv[])
{
    ifstream ifile1("/Users/dingpeien/Desktop/in_1.txt");
    ifstream ifile2("/Users/dingpeien/Desktop/in_2.txt");
    ifstream ifile3("/Users/dingpeien/Desktop/in_3.txt");
    ifstream ifile4("/Users/dingpeien/Desktop/in_4.txt");
    ifstream ifile5("/Users/dingpeien/Desktop/in_5.txt");
    
    if (!ifile1||!ifile2||!ifile3) {
        cerr<<"error:can not open input file"<<endl;
    }
    ofstream ofile("/Users/dingpeien/Desktop/out_1.txt");
    ofstream ofile2("/Users/dingpeien/Desktop/out_2.txt");
    
    int _r1,_r2,_r3,_c1,_c2,_c3;
    int vmat;
    vector<int>mat_elem1;
    vector<int>mat_elem2;
    vector < int > mat_elem3;
    while (ifile1) {
        ifile1>>_r1>>_c1;
        while (ifile1>>vmat) {
            mat_elem1.push_back(vmat);
        }
    }
    
    while (ifile2) {
        ifile2>>_r2>>_c2;
        while (ifile2>>vmat) {
            mat_elem2.push_back(vmat);
        }
    }
    
    while (ifile3) {
        ifile3>>_r3>>_c3;
        while (ifile3>>vmat) {
            mat_elem3.push_back(vmat);
        }
    }
    
    Matrix<int> mat_1(_r1,_c1);
    ofile<<"matrix 1  initialized"<<mat_1<<endl;
    input_mat_elem(mat_elem1,mat_1,_r1,_c1);
    
    Matrix<int> mat_2(_r2, _c2);
    ofile<<"matrix 2  initialized"<<mat_2<<endl;
    input_mat_elem(mat_elem2,mat_2,_r2,_c2);
    
    Matrix<int> mat_3(_r3, _c3);
    ofile<<"matrix 3  initialized"<<mat_3<<endl;
    input_mat_elem(mat_elem3,mat_3,_r3,_c3);
    
    ofile<<"matrix 1  after set"<<mat_1<<endl;
    ofile<<"matrix 2  after set"<<mat_2<<endl;
    ofile<<"matrix 3  after set"<<mat_3<<endl;
    
    
    Matrix<int> new_mat_1(mat_1);
    ofile<<"[copy constructor]~new_mat_1:member wise initialized by matrix 1"<<new_mat_1<<endl;
    
    Matrix<int> new_mat_2(5,8);
    ofile<<"new_mat_2 :5x8"<<new_mat_2<<endl;
    new_mat_2=mat_2;
    ofile<<"[copy-assignment]~new_mat_2 after memberwise assigned to matrix 2"<<new_mat_2<<endl;
    
    if (mat_1==mat_2&&mat_1==mat_3)
    { Matrix<int>new_mat_3=mat_1+mat_2+mat_3;
      ofile<<"[+]new_mat_3 :matrix 1 + matrix 2 + matrix 3"<<new_mat_3<<endl;
    }
    else ofile<<"size error[+]"<<endl;
    
    ofile<<endl;
    
   if(mat_1==mat_2)
   {
       mat_1+=mat_2;
       ofile<<"[+=]matrix 1 += matrix 2"<<mat_1<<endl;
   }
   else {ofile<<"size error[+=]"<<endl; ofile<<endl;}
    
    if (mat_1.cols()==mat_3.rows()) {
        Matrix<int>new_mat_4=mat_1*mat_3;
        ofile<<"[*]new_mat_4 :matrix 1 * matrix 3"<<new_mat_4<<endl;
    }
    else {ofile<<"size error[*]"<<endl; ofile<<endl;}
    
    
    if (mat_1.cols()==mat_1.rows()&&mat_3.rows()==mat_3.cols()&&mat_3.cols()==mat_1.cols())
    {
        mat_1*=mat_3;
        ofile<<"[*=]matrix 1 *= matrix 3"<<mat_1<<endl;
    }
    else {ofile<<"size error[*]"<<endl; ofile<<endl; }
    
    mat_2++;
    ofile<<"matrix 2++"<<mat_2<<endl;
    
    ++mat_2;
    ofile<<"++matrix 2"<<mat_2<<endl;
    
    if(mat_1==mat_2)
        ofile<<"matrix 1[cols,rows] == matrix 2[cols,rows]"<<endl;
    if(mat_1!=mat_2)
        ofile<<"matrix 1[cols,rows] != matrix 2[cols,rows]"<<endl;
    
    ofile<<"all done"<<endl;
    
  // Matrix<float> m1;
   //cout<<"please input the number of rows, cols and elements[type float]"<<endl;
   //cin>>m1;
   //cout<<m1<<endl;
   
    plural p;
    vector<plural> vp1;
    double re,me;
    int a,b;
    ifile4>>a>>b;
    while (ifile4) {
        ifile4>>re>>me;
        p.setRe(re);
        p.setIm(me);
        vp1.push_back(p);
    }
    
    
   Matrix<plural> mp1(vp1,a,b);
   ofile2<<"plural_matrix_1"<<endl;
   ofile2<<mp1<<endl;
    
    vector<plural> vp2;
    ifile5>>a>>b;
    while (ifile5) {
        ifile5>>re>>me;
        p.setRe(re);
        p.setIm(me);
        vp2.push_back(p);
    }
    
    ofile2<<"plural+matrix_2"<<endl;
    Matrix<plural>mp2(vp2,a,b);
    ofile2<<mp2<<endl;
    
    Matrix<plural> new_pmat_1(mp1);
    ofile2<<"[copy constructor]~new_pmat_1:member wise initialized by matrix 1"<<new_pmat_1<<endl;
    
    Matrix<plural> new_pmat_2(5,8);
    ofile2<<"new_pmat_2 :5x8"<<new_pmat_2<<endl;
    new_pmat_2=mp2;
    ofile2<<"[copy-assignment]~new_pmat_2 after memberwise assigned to matrix 2"<<new_pmat_2<<endl;
    
    if (mp1==mp2)
    { Matrix<plural>new_pmat_3=mp1+mp2;
        ofile2<<"[+]new_pmat_3 :plual_matrix_1 + plural_matrix_2 "<<new_pmat_3<<endl;
    }
    else ofile2<<"size error[+]"<<endl;
    
    ofile2<<endl;
    
    if(mp1==mp2)
    {
        mp1+=mp2;
        ofile2<<"[+=]plural_matrix_1 += plural_matrix_2"<<mp1<<endl;
    }
    else {ofile2<<"size error[+=]"<<endl; ofile2<<endl;}
    
    if (mp1.cols()==mp2.rows()) {
    Matrix<plural>new_pmat_4=mp1*mp2;
    ofile2<<"[*]new_pmat_4 :plural_matrix_1 * plural_matrix_2"<<new_pmat_4<<endl;
    }
    else {ofile2<<"size error[*]"<<endl; ofile2<<endl;}
    
    
    if (mp1.cols()==mp1.rows()&&mp2.rows()==mp2.cols()&&mp2.cols()==mp1.cols())
    {
        mp1*=mp2;
        ofile2<<"[*=]plural_matrix 1 *= plural_matrix 2"<<mp1<<endl;
    }
    else {ofile2<<"size error[*]"<<endl; ofile2<<endl; }
    
    ++mp1;
    ofile2<<"plural_matrix_1++"<<mp1<<endl;
    
    mp2++;
    ofile2<<"++plural_matrix_2"<<mp2<<endl;
    
    if(vp1==vp2)
        ofile2<<"size:plural_matrix_1==plural_matrix_2"<<endl;
    
    if(vp1!=vp2)
        ofile2<<"size:plural_matrix_1!=plural_matrix_2"<<endl;
    

    ofile2<<"all done"<<endl;
    return 0;
    
    
}


template <typename  t>
void input_mat_elem(const vector<t>&vec,Matrix<t>&m,int &a,int &b){
    for (int i=0,k=0; i<a; ++i) {
        for (int j=0; j<b; ++j) {
            m(i,j)=vec[k++];
        }
    }
}




