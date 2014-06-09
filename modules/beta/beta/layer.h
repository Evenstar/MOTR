//
//  layer.h
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef beta_layer_h
#define beta_layer_h
#include "stdafx.h"
using namespace std;

class InputConfig{
public:
    int inputrows;
    int inputcols;
    int noutmaps;
    int kernelsize;
    int stride;
    int side;
    shared_ptr<MatType> indata;
    vector<vector<FilterType> > filter;
    
    void Print();
    void IsSet();
};

class InputLayer {
public:
    shared_ptr<MatType>  indata;
    shared_ptr<vector<shared_ptr<MatType> > > outdata;
    vector<vector<FilterType> > filter;
private:
    int inputrows;
    int inputcols;
    
};

#endif
