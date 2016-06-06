//
//  Matrix.h
//  Assignment_2
//
//  Created by fengxinhe on 14-4-15.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#ifndef __Assignment_2__Matrix__
#define __Assignment_2__Matrix__
class Differ{};

#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "plural.h"


using namespace std;
template <typename elemType>

class Matrix{
    
    friend
    inline istream&
    operator>>( istream&  , Matrix<elemType> & );
    
    
public:
    Matrix()=default; ;                                   //constructor
    Matrix(const int &r,const int &c):_rows(r),_cols(c){
        int size = _rows*_cols;
        _matrix = new elemType[size];                     //give store
        for (int ix=0;ix<size;++ix)
            _matrix[ix]=elemType();
    }                                                    //constructor
    ~Matrix(){};
    
    Matrix(const int &r):_rows(r){}                       //constructor
    Matrix(const Matrix&);                               //copy constructor
    
    //Matrix(int rows,int columns);
    
    
    Matrix& operator=(const Matrix&);         //copy-assignment operator
    
    Matrix<elemType> operator+(Matrix &);                //矩阵元素相加
    Matrix<elemType> operator*(Matrix &);
    
    void operator+=(const Matrix&);
    void operator*=(Matrix&);
    Matrix(vector<plural>&p,int a,int b):_rows(a),_cols(b)
    {
        _matrix=new plural[p.size()-1];
        for (int x=0; x<p.size()-1; ++x) {
            _matrix[x]=p[x];
        }
    }
    
    
    Matrix<elemType>& operator++();               //++m
    Matrix<elemType> operator++(int);             //m++
    
    elemType& operator()(int row,int column)                        //允许以（x,y）的形式访问矩阵元素
    {return _matrix[row * cols() + column]; }
    
    const elemType& operator()(int row,int column) const
    {return _matrix[row * cols() + column];}
    
    int rows() const {return _rows;}
    int cols() const {return _cols;}
    
    
    bool operator==(const Matrix &m1 )
    {return rows() == m1.rows() && cols() == m1.cols();}
    bool operator!=(const Matrix&m1)
    {return rows()!=m1.rows()||cols()!=m1.cols();}
    
    bool comfortable(const Matrix &m) const
    { return (cols() == m.rows() );}
    
   ostream& print( ostream& )const;
   elemType *_matrix;

public:
    
    int _rows;
    int _cols;

};



template <typename elemType>
inline ostream&
operator<<( ostream& os ,const Matrix<elemType> &m )
{ return m.print(os);}

template <typename elemType>
istream&
operator>>( istream &is, Matrix<elemType> &m)
{
    
    
    is >> m._rows ;
    is >> m._cols;
    int size = m._rows*m._cols;
    
    m._matrix = new elemType[size];
    for (int ix=0;ix<size;++ix)
        is >> m._matrix[ix];
    
    
    return is;
}

template <typename elemType>
Matrix<elemType>::Matrix(const Matrix&rhs)
{
    _rows=rhs._rows;_cols=rhs._cols;
    int mat_size=_rows*_cols;
    _matrix=new elemType[mat_size];
    for (int ix=0; ix<mat_size; ++ix) {
        _matrix[ix]=rhs._matrix[ix];
    }
}

template <typename elemType>
Matrix<elemType>& Matrix<elemType>::
operator=(const Matrix &rhs)
{
    if (this != &rhs) {
        _rows=rhs._rows;
        _cols=rhs._cols;
        int e_cnt = _rows*_cols;
        delete [] _matrix;
        _matrix = new elemType[e_cnt];
        for (int ix=0; ix<e_cnt; ++ix) {
            _matrix[ix] = rhs._matrix[ix];
        }
    }
    return *this;
}

template <typename elemType>
Matrix<elemType> Matrix<elemType>:: operator+( Matrix& m)
{
        Matrix<elemType> temp(*this);
        int matrix_size=cols() * rows();
    
       for (int ix=0; ix<matrix_size; ++ix) {
            (temp._matrix[ix]) =(_matrix[ix]) +(m._matrix[ix]);
        }
        return temp;
}
    
template<typename elemType>
Matrix<elemType> Matrix<elemType>::operator*( Matrix&m)
{
    Matrix<elemType> result(rows(),m.cols() );
    elemType temp=0;
    for(int i=0;i<rows();i++)
        for(int j=0;j<m.cols();j++)
        {
            result._matrix[i*m.cols()+j] = 0.0;
            for(int k=0;k<cols();k++)
                temp=((_matrix[i*cols()+k])*(m._matrix[k*m.cols()+j]));
                result._matrix[i*m.cols()+j]+=temp;
        }
        return result;
}


template <typename elemType>
void Matrix<elemType>::operator+=(const Matrix &m) {
    int matrix_size=cols() * rows();
    for (int ix=0; ix<matrix_size; ++ix) {
         *(_matrix + ix) = *(_matrix + ix) + *(m._matrix +ix);
    }
}

/*template <typename elemType>
Matrix<elemType>
operator*( const Matrix<elemType> &m1,const Matrix<elemType> &m2)
{
    Matrix<elemType> result(m1.rows(),m2.clos() );
    for (int ix=0; ix<m1.rows(); ix++) {
        for (int jx=0; jx<m1.cols; jx++) {
            result(ix,jx) = 0;
            for (int kx=0; kx<m1.cols; kx++) {
                result(ix,jx) += m1(ix,kx) * m2(kx,jx);
            }
        }
    }
    return result;
}
*/
template <typename elemType>
void Matrix<elemType>::operator*=(Matrix &m){
    for (int x=0; x<rows(); x++) {
        for (int j=0; j<rows(); j++) {
            for (int k=0; k<rows(); k++) {
                _matrix[x*rows()+j]=_matrix[x*cols()+k]*m._matrix[k*cols()+j];
            }
        }
    }
}

template <typename elemType>
Matrix<elemType>
&Matrix<elemType>::operator++()
{
    int r=rows();
    int c=cols();
    int size=r*c;
    for (int ix=0; ix<size;++ix){
        ++*(_matrix+ix);
    }
    return *this;
}

template <typename elemType>
Matrix<elemType>
Matrix<elemType>::operator++(int)
{
    int r=rows();
    int c=cols();
    int size=r*c;
    for (int ix=0; ix<size;++ix){
        ++*(_matrix+ix);
    }
    return *this;
}



template <typename elemType>
ostream& Matrix<elemType>::print(ostream &os) const{
    int col=cols();
    int matrix_size=col * rows();
    os<<endl;
    os<<rows()<<" "<<cols()<<endl;
    for (int ix=0; ix<matrix_size; ix++) {
        if( ix % col == 0) os<<endl;
        os<<(*(_matrix + ix))<<' '<<' ';
    }
    os<<endl;
    //delete []_matrix;
    return os;
}




#endif /* defined(__Assignment_2__Matrix__) */
