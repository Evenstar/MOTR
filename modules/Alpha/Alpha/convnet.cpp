//
//  convnet.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "convnet.h"

void ConvNet::Initialize(){
    layer.clear();
    xtrain=NULL;
    ytrain=NULL;
    int i=0;
    for(; i< config.nconvlayers;i++){
        ConvLayer* convlayer=new ConvLayer(config.vconfig[i]);
        layer.push_back(convlayer);
    }
    for (; i<config.nconvlayers+config.nfclayers;i++){
        FullyConnectedLayer* fclayer=new FullyConnectedLayer(config.vconfig[i]);
        layer.push_back(fclayer);
    }
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
