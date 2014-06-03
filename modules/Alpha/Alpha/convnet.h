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
    ConvNet(const NetConfig& _config) {
        config=_config;
        for(int i=0; i<config.nconvlayers; i++){
            convlayer.push_back(ConvLayer(config.convconfig[i]));
        }
        convlayer.begin()->indata=config.indata;
        for(int i=1; i<config.nconvlayers; i++){
            convlayer[i].indata=convlayer[i-1].outdata;
        }
    }
    
    void run(){
        for(int i=0; i<convlayer.size(); i++){
            cout<<"Running "<<i<<endl;
            convlayer[i].run();
        }
    }
    
    void print(){
        for(int i=0; i<convlayer.size(); i++){
            cout<<"Layer "<<i<<endl;
            convlayer[i].print();
        }
    }
public:
    vector<ConvLayer> convlayer;
    NetConfig config;
};

#endif
