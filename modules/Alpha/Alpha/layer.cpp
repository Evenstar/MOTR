//
//  convlayer.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "layer.h"


ConvLayer::ConvLayer(int _stride, int _side, int _kernelsize,
                     int _ninmaps, int _noutmaps)
{
    stride=_stride;
    side=_side;
    kernelsize=_kernelsize;
    ninmaps=_ninmaps;
    noutmaps=_noutmaps;
    indata=NULL;
}

void ConvLayer::SetFilter(const vector<FilterType>& f)
{
    filter=f;
}


void ConvLayer::SetInput( vector<MatType>* in)
{
    indata=in;
}

void ConvLayer::SetReceiveset(const vector<set<int> >& rec)
{
    receiveset=rec;
}

void ConvLayer::Setup(int _stride, int _side, int _kernelsize,
                      int _ninmaps, int _noutmaps)
{
    stride=_stride;
    side=_side;
    kernelsize=_kernelsize;
    ninmaps=_ninmaps;
    noutmaps=_noutmaps;
}



void ConvLayer::ApplyFilter()
{
    outdata.clear();
    for(int j=0; j<noutmaps; j++){
        MatType z=Conv2((*indata)[0],filter[0],Valid);
        z=MatType::Zero(z.rows(),z.cols());
        for (int i=0;i<ninmaps;i++){
            MatType temp=Conv2((*indata)[i],filter[i*noutmaps+j],Valid);
            z=z+temp;
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























FullyConnectedLayer::FullyConnectedLayer( int _stride, int _side )
{
    stride=_stride;
    side=_side;
}

void FullyConnectedLayer::Setup(int _stride, int _side)
{
    stride=_stride;
    side=_side;
}