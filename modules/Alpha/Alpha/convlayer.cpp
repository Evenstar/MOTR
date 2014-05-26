//
//  convlayer.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "convlayer.h"


void ConvLayer::SetFilter(const vector<FilterType>& f)
{
    filter=f;
}


void ConvLayer::SetIndata( vector<MatType>* in)
{
    indata=in;
}