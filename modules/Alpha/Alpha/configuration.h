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
class Configuration{
public:
    
    ///Parameters for convlayer block
    int nconvlayers;
    vector<int> stride;
    vector<int> side;
    vector<vector<set<int> > > inmaps;
    vector<string> nonlinearity;
    vector<int> kernelsize;
    vector<int> nmaps;
    int ninputrows;
    int ninputcols;
    vector<bool> isdownsample;
    
    ///last term is the size of the input of the fully connected layer.
    vector<int> nconvrows;
    vector<int> nconvcols;
    
    ///Parameters for fully connected block
    
    int nfclayers;
    vector<int> nfcnodes;
    string objtype;
    
    ///TODO: add learning module.
    
public:
    void ComputeSize();
};


#endif
