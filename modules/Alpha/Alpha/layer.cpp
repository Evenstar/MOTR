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























FullyConnectedLayer::FullyConnectedLayer( int _stride, int _side,
                                         int _fanin, int _fanout)
{
    stride=_stride;
    side=_side;
    fanin=_fanin;
    fanout=_fanout;
}

void FullyConnectedLayer::Setup(int _stride, int _side
                                ,int _fanin, int _fanout)
{
    stride=_stride;
    side=_side;
    fanin=_fanin;
    fanout=_fanout;
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

void FullyConnectedLayer::DownSample()
{
    outdata=MaxPooling(outdata, stride,side);
}













