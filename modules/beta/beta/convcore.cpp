//
//  convcore.cpp
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "convcore.h"

using namespace arma;
MatType Conv2_Valid(const MatType& a, const MatType& b)
{
    int m=a.n_rows;
    int n=a.n_cols;
    int l1=b.n_rows;
    int l2=b.n_cols;
    MatType c(l1,l2);
    c.zeros();
    for(int i=0; i<l1; i++){
        for(int j=0; j<l2; j++){
            c(i,j)=b(l1-1-i,l2-1-j);
        }
    }
    MatType g(m-l1+1,n-l2+1);
    for (int k1=0; k1<m-l1+1;k1++){
        for (int k2=0; k2<n-l2+1; k2++){
            float s=0;
            s=sum(sum(a.submat(k1,k2,k1+l1-1,k2+l2-1)%c));
            g(k1,k2)=s;
        }
    }
    return g;
}


MatType Conv2(const MatType& a, const MatType& b, string boundarytype){
    if (boundarytype!="valid" && boundarytype!="full")
    {
        LOG(FATAL)<<"Invalid boundary type.\n";
        exit(-1);
    }
    if (boundarytype=="valid")
    {
        return Conv2_Valid(a,b);
    }
    else
    {
        MatType aext=zeros(a.n_rows+2*(b.n_rows-1),a.n_cols+2*(b.n_cols-1));
        int r1=b.n_rows-1;
        int r2=b.n_cols-1;
        aext.submat(r1,r2,r1+a.n_rows-1,r2+a.n_rows-1)=a;
        return Conv2_Valid(aext, b);
    }
}

MatType maxpooling(const MatType& mat,int stride, int side)
{
    int m=mat.n_rows;
    int n=mat.n_cols;
    int rows=floor((m-side)/stride)+1;
    int cols=floor((n-side)/stride)+1;
    MatType  result(rows,cols);
    for(int i=0; i<=m-side; i+=stride){
        for(int j=0; j<=n-side;j+=stride){
            double s=max(max(abs(mat.submat(i,j,i+side-1,j+side-1))));
            result(i/stride,j/stride)=s;
        }
    }
    return result;
}


MatType maxpooling2(const MatType& mat,int stride, int side)
{
    int m=mat.n_rows;
    int n=mat.n_cols;
    int rows=floor((m-side)/stride)+1;
    int cols=floor((n-side)/stride)+1;
    MatType  result(rows,cols);
    for(int i=0; i<=m-side; i+=stride){
        for(int j=0; j<=n-side;j+=stride){
            double s=0;
            for(int k=0; k<side; k++){
                for(int l=0; l<side;l++){
                    if (abs(mat(i+k,j+l))>s){
                        s=abs(mat(i+k,j+l));
                    }
                }
            }
            result(i/stride,j/stride)=s;
        }
    }
    return result;
}





























