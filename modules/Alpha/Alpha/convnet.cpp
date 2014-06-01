//
//  convnet.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "convnet.h"
using namespace boost;
void ConvNet::Initialize(){
    ///1.set initial parameters.
    int i=0;
    for(; i< config.nconvlayers;i++){
        shared_ptr<ConvLayer> ptr(new ConvLayer(config.vconfig[i]));
        layer.push_back(ptr);
    }
    for (; i<config.nconvlayers+config.nfclayers;i++){
        shared_ptr<FullyConnectedLayer> ptr(new FullyConnectedLayer(config.vconfig[i]));
        layer.push_back(ptr);
    }
    
    ///2.link the convolutional layers.
    ///3.concatenate the data.
        //do this at run time.
    ///4.link the fully connected layers.
    
    
}


void ConvNet::SetTrainingData(VecMatPtr _xtrain, VecMatPtr _ytrain)
{
    xtrain=_xtrain;
    ytrain=_ytrain;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
