//
//  layer.cpp
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "layer.h"
#include "convcore.h"
InputLayer::InputLayer(const InputConfig& _cfg)
{
    cfg=_cfg;
    for(int i=0; i<cfg.noutmaps; i++){
        filter.push_back(new MatType);
        outdata.push_back(new MatType);
    }
}

void InputConfig::Print()
{
    cout<<"inputrows    "<<inputrows<<endl;
    cout<<"inputcols    "<<inputcols<<endl;
    cout<<"noutmaps     "<<noutmaps<<endl;
    cout<<"kernelsize   "<<kernelsize<<endl;
    cout<<"stride       "<<stride<<endl;
    cout<<"side         "<<side<<endl;
}

void InputLayer::Print()
{
    cout<<"Info for InputLayer";
    cfg.Print();
    if (filter.empty()){
        cout<<"filter:      empty"<<endl;
    } else {
        cout<<"filter:      {";
        for(int i=0; i<filter.size();i++){
            cout<<"("<<filter[i]->n_rows<<","
                <<filter[i]->n_cols<<"),";
        }
        cout<<"}"<<endl;
    }
    
    if (indata==0){
        cout<<"indata:      empty"<<endl;
    } else {
        cout<<"indata:      ("<<indata->n_rows
        <<","<<indata->n_cols<<")"<<endl;
    }
    
    if (outdata.empty()){
        cout<<"outdata      empty"<<endl;
    } else {
        cout<<"outdata:      {";
        for(int i=0; i<outdata.size();i++){
            cout<<"("<<outdata[i]->n_rows<<","
            <<outdata[i]->n_cols<<"),";
        }
        cout<<"}"<<endl;
    }
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

void InputLayer::SetFilter(const vector<MatType*> & _filter)
{
    for(int i=0; i<filter.size();i++){
        *filter[i]=*_filter[i];
    }
}

void InputLayer::SetFilter(const MatType& _mat, int i)
{
    if (i<0 || i>=filter.size()){
        LOG(DEBUG)<<"index out of range, filter not assigned";
        return ;
    } else {
        *filter[i]=_mat;
    }
}

void InputLayer::applyfilter()
{
    for(int i=0; i<cfg.noutmaps; i++){
        *outdata[i]=Conv2(*indata,*filter[i],"valid");
    }
}
