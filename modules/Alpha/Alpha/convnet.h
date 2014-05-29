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
#include "configuration.h"
using namespace std;



class ConvNet{
public:
    ConvNet(const Configuration& _config):config(_config){};

    ~ConvNet(){};
    
    void Initialize();
    
    void SetTrainingData(vector<MatType>*, vector<MatType>*);
    
    void FeedForward();
    
    void BackPropagation();
    
    void Train();
    
    void ApplyGradient();
    
    float Objecteive();
    
public:
    
    vector<MatType>* xtrain;
    vector<MatType>* ytrain;
    vector<Layer*> layer;
    Configuration config;
};


#endif
