//
//  convlayer.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "layer.h"



void ConvLayer::SetInput( vector<MatType>* _indata)
{
    if (_indata->size()==0){
        cerr<<"Input data must not be empty."<<endl;
    }
    long _rows=(*_indata)[0].rows();
    long _cols=(*_indata)[0].cols();
    if ( (_rows!=inputrows) || (_cols!=inputcols)){
        cerr<<"Wrong input size during initialization of Convlayer"<<endl;
    } else{
        indata=_indata;
    }
}


void ConvLayer::SetFilter(const vector<vector<FilterType> >& _filter)
{
    filter=_filter;
}


void ConvLayer::SetInmaps(const vector<set<int> >& _inmaps)
{
    inmaps=_inmaps;
}

///TODO: the index order is filter[j][i], inmaps[j][i], not the other way around.
void ConvLayer::ApplyFilter()
{
    outdata.clear();
    for (int j=0; j<noutmaps; j++){
        MatType z=MatType::Zero(inputrows-kernelsize+1, inputcols-kernelsize+1);
        for (int i=0; i<inmaps[j].size();i++){
            MatType temp=Conv2((*indata)[i],filter[j][i],"valid");
            z+=temp;
        }
        outdata.push_back(z);
    }
}

void ConvLayer::DownSample()
{
    vector<MatType> newvec;
    for (int i=0; i<outdata.size(); i++){
        MatType mat=outdata[i];
        newvec.push_back(MaxPooling(mat,stride,side));
    }
    outdata.clear();
    outdata=newvec;
    
}

void ConvLayer::ApplyNonlinearity(){
    vector<MatType> newvec;
    for (int i=0; i<outdata.size(); i++){
        MatType mat=outdata[i];
        newvec.push_back(ApplyReLU(mat));
    }
    outdata.clear();
    outdata=newvec;
}


bool ConvLayer::SelfCheck()
{
    cout<<"Running Selfcheck of ConvLayer"<<endl;
    if( inputrows<=0 || inputcols<=0){
        cerr<<"Input matrix is 0"<<endl;
        return false;
    }else{
        cout<<"Input matrix is of size "<<inputrows<<" "<<inputcols<<endl;
    }
    
    if (indata==NULL || indata->size()==0){
        cerr<<"Input data is empty."<<endl;
        return false;
    } else{
        if (indata->size()!=ninmaps){
            cerr<<"indata size and ninmaps don't match"<<endl;
            return false;
        }
        else{
            cout<<"Number of input maps is "<<ninmaps<<endl;
        }
    }
    
    if (filter.size()==0){
        cerr<<"Filter is not set"<<endl;
        return false;
    }
    
    if (kernelsize<=0){
        cerr<<"Kernel size must be positive"<<endl;
        return false;
    }
    
    for (int i=0; i<filter.size();i++){
        for(int j=0; j<filter[i].size();j++){
            if (filter[i][j].rows()!=kernelsize || filter[i][j].cols()!=kernelsize){
                cerr<<"Filter must be of the same size"<<endl;
                return false;
            }
        }
    }
    cout<<"Filter size is "<<kernelsize<<" "<<kernelsize<<endl;
    if (filter.size()!=inmaps.size()){
        cerr<<"Filter size and inmaps size don't match"<<endl;
        return false;
    }
    
    for (int i=0; i<filter.size(); i++){
        if (filter[i].size()!=inmaps[i].size()){
            cerr<<"Filter size and inmaps size don't match"<<endl;
            return false;
        }
    }
    cout<<"Number of nodes is "<<filter.size()<<endl;
    for (int i=0; i<inmaps.size(); i++){
        cout<<"The input map of node "<<i<<" is: ";
        for(set<int>::iterator it=inmaps[i].begin(); it!=inmaps[i].end(); it++)
        {
            cout<<" "<<(*it);
        }
        cout<<endl;
    }
    return true;
}


void FullyConnectedLayer::SetInput(MatType* mat)
{
    indata=mat;
}

void FullyConnectedLayer::SetWeight(const MatType & mat)
{
    Weight=mat;
}

void FullyConnectedLayer::ApplyFilter()
{
    outdata=Weight*(*indata);
}

void FullyConnectedLayer::ApplyNonlinearity()
{
    outdata=ApplyReLU(outdata);
}









