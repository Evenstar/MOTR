//
//  helper.cpp
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "utils.h"
using namespace std;
using namespace cv;

void LoadFilter(vector<FilterType>& filter, string fname)
{
    ifstream fin(fname.c_str());
    if (!fin){
        cerr<<"Cannot load filter."<<endl;
    }
    int m, r;
    fin>>m>>r;
    filter.clear();
    for(int i=0; i<m; i++){
        FilterType a(r,r);
        for(int j=0; j<r*r; j++){
            fin>>a(j-r*(j/r),j/r);
        }
        filter.push_back(a);
    }
    fin.close();
}


MatType Conv2_Valid(const MatType& a, const MatType& b)
{
    long m=a.rows();
    long n=a.cols();
    long l1=b.rows();
    long l2=b.cols();
    MatType g;
    g=MatType(m-l1+1,n-l2+1);
    for (long k1=0; k1<m-l1+1;k1++){
        for (long k2=0; k2<n-l2+1; k2++){
            float s=0;
            for (long j1=0; j1<l1; j1++){
                for (long j2=0; j2<l2; j2++){
                    s+=a(k1+j1,k2+j2)*b(l1-1-j1,l2-1-j2);
                }
            }
            g(k1,k2)=s;
        }
    }
    return g;
}

MatType Conv2(const MatType& a, const MatType& b, string boundarytype){
    if (boundarytype!="valid" && boundarytype!="full")
    {
        cerr<<"Invalid boundary type.\n";
        exit(-1);
    }
    if (boundarytype=="valid")
    {
        return Conv2_Valid(a,b);
    }
    else
    {
        MatType aext=MatType::Zero(a.rows()+2*(b.rows()-1),a.cols()+2*(b.cols()-1));
        long r1=b.rows()-1;
        long r2=b.cols()-1;
        aext.block(r1,r2,a.rows(),a.cols())=a;
        return Conv2_Valid(aext, b);
    }
}


MatType Img2Mat(ImgType& img)
{
    int rows=img.rows;
    int cols=img.cols;
    MatType mat(rows,cols);
    float* p;
    for (int i=0; i<rows; i++){
        p=img.ptr<float>(i);
        for(int j=0; j<cols; j++){
            mat(i,j)=p[j];
        }
    }
    return mat;
}


ImgType Mat2Img(MatType& mat)
{
    long rows=mat.rows();
    long cols=mat.cols();
    ImgType img(rows,cols,CV_32FC1);
    float* p;
    for (int i=0; i<rows; i++){
        p=img.ptr<float>(i);
        for(int j=0; j<cols; j++){
            p[j]=mat(i,j);
        }
    }
    return img;
}


vector<FilterType> GenerateRandomFilter(int _ninmaps, int _noutmaps,
                                        int _kernelsize)
{
    vector<FilterType> filter;
    for (int i=0; i< _ninmaps; i++){
        for(int j=0;j< _noutmaps; j++){
            FilterType m=FilterType::Random(_kernelsize, _kernelsize);
            filter.push_back(m);
        }
    }
    return filter;
}

MatType GenerateRandomWeights(int _fanin, int _fanout)
{
    return FilterType::Random(_fanin,_fanout);
}



MatType MaxPooling(const MatType & mat, int stride, int side)
{
    long m=mat.rows();
    long n=mat.cols();
    long rows=floor((m-side)/stride)+1;
    long cols=floor((n-side)/stride)+1;
    MatType result(rows,cols);
    for (int i=0; i<m-side; i+=stride){
        for(int j=0; j<n-side; j+=stride){
            float s=0;
            for (int k=0; k<side; k++){
                for(int l=0; l<side; l++){
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



MatType ApplyReLU(const MatType& mat)
{
    MatType result(mat.rows(),mat.cols());
    for (int i=0; i< mat.rows(); i++)
    {
        for (int j=0; j<mat.cols(); j++)
        {
            result(i,j)= mat(i,j)>0? mat(i,j) : 0;
        }
    }
    return result;
}


void printVector(VecMatPtr ptr){
    if (ptr->empty()){
        cout<<"empty"<<endl;
    } else{
        cout<<"size "<<ptr->size()<<"\t"<<"{";
        for(int i=0; i<ptr->size();i++){
            cout<<"("<<(*ptr)[i].rows()<<","<<(*ptr)[i].cols()<<")"<<",";
        }
        cout<<"}"<<endl;
    }
    
}

void displayVector(VecMatPtr ptr){
    if (ptr->empty()){
        return ;
    } else {
        for(int i=0; i<ptr->size();i++){
            ImgType img=Mat2Img((*ptr)[i]);
            stringstream ss;
            ss<<i;
            ImgType _img;
            normalize(img, _img, 0, 1, NORM_MINMAX, CV_32FC1);
            namedWindow(ss.str(),CV_WINDOW_AUTOSIZE);
            imshow(ss.str(),_img);
        }
    }
    waitKey(0);
    
}


int ReverseInt (int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1=i&255;
    ch2=(i>>8)&255;
    ch3=(i>>16)&255;
    ch4=(i>>24)&255;
    return((int)ch1<<24)+((int)ch2<<16)+((int)ch3<<8)+ch4;
}


void ReadMnist(vector<MatType>& xtrain, vector<MatType>& ytrain)
{
    string prefix("/Users/chengtai/Documents/2014/MOTR/modules/Alpha/data/mnist");
    ifstream file;
    string filename=prefix+string("/train-images-idx3-ubyte");
    file.open(filename.c_str(), ios::binary);
    int magicnumber=2051;
    int nimages=60000;
    int rows=28;
    int cols=28;
    unsigned char temp;
    
    file.read((char*)&magicnumber,sizeof(magicnumber));
    magicnumber=ReverseInt(magicnumber);
    if (magicnumber!=2051){
        cout<<"Error while reading mnist."<<endl;
        exit(-1);
    }
    file.read((char*)&nimages,sizeof(int));
    file.read((char*)&rows,sizeof(int));
    file.read((char*)&cols,sizeof(int));
    
    for(int k=0; k<60000; k++){
        MatType z(28,28);
        for(int i=0; i<28;i++){
            for(int j=0;j<28;j++){
                file.read((char*)&temp, sizeof(temp));
                z(i,j)=(float)temp;
            }
        }
        xtrain.push_back(z);
    }
    file.close();
    
    
    filename=prefix+string("/train-labels-idx1-ubyte");
    file.open(filename.c_str(),ios::binary);
    file.read((char*)&magicnumber,sizeof(magicnumber));
    magicnumber=ReverseInt(magicnumber);
    if (magicnumber!=2049){
        cout<<"Error while reading mnist."<<endl;
        exit(-1);
    }
    file.read((char*)&nimages,sizeof(int));
    
    for(int i=0 ;i<60000;i++){
        MatType z=MatType::Zero(10,1);
        file.read((char*)&temp,sizeof(temp));
        z((int)temp,0)=1;
        ytrain.push_back(z);
    }
    file.close();
}












