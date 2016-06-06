//
//  Matrix.cpp
//  Assignment_2
//
//  Created by fengxinhe on 14-4-15.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//

#import "Matrix.h"


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
Matrix<elemType>
operator+(const Matrix<elemType> &m1,const Matrix<elemType> &m2)
{
    if (m1._rows==m2.rows&&m1._cols==m2._cols) {
        
        Matrix<elemType>result(m1);
        result += m2;
        return result;
    }
    else
        cerr<<"these two matrixs can not be added"<<endl;
    
}

template <typename elemType>
void Matrix<elemType>::operator+=(const Matrix &m) {
    int matrix_size=cols() * rows();
    for (int ix=0; ix<matrix_size; ++ix) {
        ( *(_matrix + ix)) += ( *(m._matrix +ix));
    }
}

template <typename elemType>
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

template <typename elemType>
void Matrix<elemType>::operator*=(Matrix &m){
    for (int ix=0; ix<rows(); ++ix) {
        for (int jx=0; jx<cols(); ++jx) {
            m(ix,jx)=m(ix,jx)*m(ix,jx);
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
    os<<rows()<<cols()<<endl;
    for (int ix=0; ix<matrix_size; ix++) {
        if( ix % col == 0) os<<endl;
        os<<(*(_matrix + ix))<<' ';
    }
    os<<endl;
    //delete []_matrix;
    return os;
}
