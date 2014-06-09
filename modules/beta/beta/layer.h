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
    InputConfig(int _inputrows=0, int _inputcols=0,
                int _noutmaps=0, int _kernelsize=0,
                int _stride=0, int _side=0):
    inputrows(_inputrows),inputcols(_inputcols),
    noutmaps(_noutmaps), kernelsize(_kernelsize),
    stride(_stride),side(_side){};
public:
    int inputrows;
    int inputcols;
    int noutmaps;
    int kernelsize;
    int stride;
    int side;
    void Print();
};

class InputLayer {
public:
    InputLayer(const InputConfig& _cfg):cfg(_cfg){};
    ~InputLayer();
    
    void Print();
public:
    MatType*  indata;
    vector<MatType*> outdata;
    vector<MatType*> filter;
    InputConfig cfg;
};

#endif
