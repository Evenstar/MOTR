//
//  convnet.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "convnet.h"

ConvNet::ConvNet()
{
    xtraindata=NULL;
    ytraindata=NULL;
    
}

void ConvNet::Setup( const Config& _config)
{
    config=_config;
    for (int i=0; i<config.nconvlayers;i++){
        ConvLayer temp(config.stride[i], config.side[i], config.kernelsize[i],
                       config.ninmaps[i], config.noutmaps[i]);
        temp.name="c";
        layer.push_back(temp);
    }
    
    for(int i=0; i<config.nfclayers; i++) {
        FullyConnectedLayer temp(config.stride[i], config.side[i],
                                config.fanin[i],config.fanout[i]);
        temp.name="f";
        layer.push_back(temp);
    }
    cout<<layer.size()<<endl;
}

