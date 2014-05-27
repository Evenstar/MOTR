//
//  convnet.h
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef CONVNET_H
#define CONVNET_H

#include "layer.h"
using namespace std;

struct Config{
    int nconvlayers;
    int nfclayers;
    int batchsize;
    int nepoches;
    float learningrate;

    vector<int> kernelsize;
    vector<int> stride;
    vector<int> side;
    vector<set<int> > receiveset;
};

class ConvNet{
public:
    ConvNet(){};

    ~ConvNet(){};
    
    void Setup(const Config&);
    
    void Initialize();
    
    void FeedForward();
    
    void BackPropagation();
    
    void Train();
    
    void ApplyGradient();
    
    float Objecteive();
    
public:
    
    vector<MatType>* xtraindata;
    vector<MatType>* ytraindata;
    
    vector<Layer> layer;
    vector<MatType> xdata;
    MatType ydata;
    
    vector<MatType> xdelta;
    MatType ydelta;
    
    Config config;
};


#endif
