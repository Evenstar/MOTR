//
//  Configuration.h
//  Alpha
//
//  Created by ChengTai on 5/28/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "utils.h"
using namespace std;

struct ConvConfig{
    int ninmaps;
    int inputrows;
    int inputcols;
    int stride;
    int side;
    int kernelsize;
    int noutmaps;
    bool isdownsample;
    vector<set<int> > inmaps;
    vector<vector<FilterType> > filter;
    VecMatPtr indata;
};
#endif
