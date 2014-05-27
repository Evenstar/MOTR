//
//  convlayer.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "layer.h"


ConvLayer::ConvLayer(int _stride, int _side, int _kernelsize)
{
    stride=_stride;
    side=_side;
    kernelsize=_kernelsize;
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

void ConvLayer::Setup(int _stride, int _side, int _kernelsize)
{
    stride=_stride;
    side=_side;
    kernelsize=_kernelsize;
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