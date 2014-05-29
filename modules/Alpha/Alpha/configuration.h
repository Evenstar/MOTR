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

struct Config{
    ///for convlayers.
    int ninmaps;
    int inputrows;
    int inputcols;
    int stride;
    int side;
    int kernelsize;
    int noutmaps;
    bool isdownsample;
    vector<set<int> > inmaps;

    ///for fully connected layers.
    int fanin;
    int fanout;
};

struct Configuration{
public:
    int nconvlayers;
    int nfclayers;
    vector<Config> vconfig;
};


#endif
