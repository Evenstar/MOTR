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
    int i=0;
    for(; i< config.nconvlayers;i++){
        shared_ptr<ConvLayer> ptr(new ConvLayer(config.vconfig[i]));
        layer.push_back(ptr);
    }
    for (; i<config.nconvlayers+config.nfclayers;i++){
        shared_ptr<FullyConnectedLayer> ptr(new FullyConnectedLayer(config.vconfig[i]));
        layer.push_back(ptr);
    }
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
