//
//  configuration.cpp
//  Alpha
//
//  Created by ChengTai on 5/28/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "configuration.h"

void Configuration::ComputeSize()
{
    int rows=ninputrows;
    int cols=ninputcols;
    for(int i=0; i< nconvlayers; i++)
    {
        rows-=kernelsize[i];
        cols-=kernelsize[i];
        nconvrows.push_back(rows);
        nconvcols.push_back(cols);
        rows=floor((rows-side[i])/stride[i])+1;
        cols=floor((cols-side[i])/stride[i])+1;
    }
}