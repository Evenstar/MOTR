//
//  layer.cpp
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "layer.h"
void InputConfig::Print()
{
    cout<<"inputrows    "<<inputrows<<endl;
    cout<<"inputcols    "<<inputcols<<endl;
    cout<<"noutmaps     "<<noutmaps<<endl;
    cout<<"kernelsize   "<<kernelsize<<endl;
    cout<<"stride       "<<stride<<endl;
    cout<<"side         "<<side<<endl;
}

void InputLayer::Print(){
    cout<<"Info for InputLayer"<<endl;
    cfg.Print();
}

InputLayer::~InputLayer()
{
    for(int i=0; i<outdata.size(); i++){
        delete outdata[i];
    }
    for(int i=0; i<filter.size(); i++){
        delete filter[i];
    }
    indata=0;
}