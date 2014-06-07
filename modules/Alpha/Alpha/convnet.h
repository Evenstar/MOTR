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

///TODO: memory leak fix.
using namespace std;
class ConvNet{
public:
    ConvNet(const NetConfig& _config) {
        config=_config;
        for(int i=0; i<config.nconvlayers; i++){
            convlayer.push_back(ConvLayer(config.convconfig[i]));
        }
        for(int i=0; i<config.nfulllayers; i++){
            fulllayer.push_back(FullLayer(config.fullconfig[i]));
        }
        
        convlayer.begin()->indata=new vector<MatType>;
        for(int i=1; i<config.nconvlayers; i++){
            convlayer[i].indata=convlayer[i-1].outdata;
        }
        fulllayer.begin()->indata=new MatType;
        for(int i=1; i<config.nfulllayers;i++){
            fulllayer[i].indata=fulllayer[i-1].outdata;
        }
    }
    
    void run(){
        VecMatPtr ptr=config.indata;
        for(int k=0; k<config.indata->size();k++){
            convlayer[0].indata->clear();
            convlayer[0].indata->push_back((*ptr)[k]);
            for(int i=0; i<convlayer.size(); i++){
                convlayer[i].run();
                cout<<(*convlayer[i].outdata)[0]<<endl;
            }
            (*fulllayer[0].indata)=convert(*(convlayer[config.nconvlayers-1].outdata));
            for(int i=0; i<fulllayer.size(); i++){
                fulllayer[i].run();
                cout<<fulllayer[i].outdata->transpose()<<endl;
            }
            outdata.push_back(output());
        }
    }
    
    void print(){
        for(int i=0; i<convlayer.size(); i++){
            cout<<"ConvLayer    "<<i<<endl;
            convlayer[i].print();
        }
        for(int i=0; i<fulllayer.size(); i++){
            cout<<"FullLayer    "<<i<<endl;
            fulllayer[i].print();
        }
    }
    
public:
    vector<ConvLayer> convlayer;
    vector<FullLayer> fulllayer;
    NetConfig config;
    vector<MatType> outdata;
private:
    MatType convert(vector<MatType> data);
    MatType output(){
        int n=fulllayer.size();
        return *(fulllayer[n-1].outdata);
    }
};
#endif
