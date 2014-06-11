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

void InputConfig::print()
{
    cout<<"inputrows    "<<inputrows<<endl;
    cout<<"inputcols    "<<inputcols<<endl;
    cout<<"noutmaps     "<<noutmaps<<endl;
    cout<<"kernelsize   "<<kernelsize<<endl;
    cout<<"stride       "<<stride<<endl;
    cout<<"side         "<<side<<endl;
}

void InputLayer::print()
{
    cout<<"Info for InputLayer"<<endl;
    cfg.print();
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
        cout<<"outdata:     {";
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

void InputLayer::setfilter(const vector<MatType*> & _filter)
{
    for(int i=0; i<filter.size();i++){
        *filter[i]=*_filter[i];
    }
}

void InputLayer::setfilter(const MatType& _mat, int i)
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
        *outdata[i]=conv2(*indata,*filter[i],"valid");
    }
}

void InputLayer::downsample()
{
    for(int i=0; i<outdata.size();i++){
        *outdata[i]=maxpooling(*outdata[i], cfg.stride, cfg.side);
    }
}

void InputLayer::randominit()
{
    for(int i=0; i<cfg.noutmaps; i++) {
        *filter[i]=randu<MatType>(cfg.kernelsize,cfg.kernelsize)/cfg.kernelsize/cfg.kernelsize;
    }
}

void InputLayer::run()
{
    applyfilter();
    downsample();
}

void ConvlayerConfig::setdefaultinmaps()
{
    for(int i=0; i<noutmaps; i++)
    {
        vector<int> a(permaps);
        inmap.push_back(a);
    }
}

void ConvlayerConfig::print()
{
    InputConfig::print();
    cout<<"permaps:     "<<permaps<<endl;
    cout<<"ninmaps      "<<ninmaps<<endl;
    if (inmap.empty()) {
        cout<<"inmap:      empty"<<endl;
    } else {
        cout<<"inmap:      {";
        for(int i=0; i<inmap.size(); i++){
            cout<<"("<<i<<":";
            for(int j=0; j<inmap[i].size(); j++){
                cout<<inmap[i][j]<<",";
            }
            cout<<"),";
        }
        cout<<"}"<<endl;
    }
}

ConvLayer::ConvLayer(const ConvlayerConfig& _cfg)
{
    cfg=_cfg;
    for(int i=0; i<cfg.ninmaps; i++){
        indata.push_back(new MatType);
    }
    for(int i=0; i<cfg.noutmaps; i++)    {
        outdata.push_back(new MatType);
        vector<MatType*> temp;
        for(int j=0; j<cfg.permaps; j++) {
            temp.push_back(new MatType);
        }
        filter.push_back(temp);
    }
}

void ConvLayer::print()
{
    cout<<"Info for ConvLayer"<<endl;
    cfg.print();
    if (filter.empty()){
        cout<<"filter:      empty"<<endl;
    } else {
        cout<<"filter:      {";
        for(int i=0; i<filter.size();i++){
            cout<<"["<<i<<":";
            for(int j=0; j<filter[i].size();j++){
                cout<<"("<<filter[i][j]->n_rows<<","<<filter[i][j]->n_cols<<"),";
            }
            cout<<"],";
        }
        cout<<"}"<<endl;
    }
    
}

void ConvLayer::setfilter(const vector<vector<MatType*> >& _filter)
{
    for(int i=0; i<filter.size(); i++){
        for(int j=0; j<filter[i].size(); j++) {
            *filter[i][j]=*_filter[i][j];
        }
    }
}

void ConvLayer::setfilter(const MatType& mat, int i, int j)
{
    if( i<0 || i>=filter.size() || j<0 || j>=filter[0].size()) {
        LOG(DEBUG)<<"index out of range, filter not assigned";
        return ;
    } else {
        *filter[i][j]=mat;
    }
}

void ConvLayer::randominit()
{
    for(int i=0; i<filter.size(); i++) {
        for(int j=0; j<cfg.permaps; j++){
            int id=rand()%cfg.ninmaps;
            cfg.inmap[i][j]=id;
        }
        for(int j=0; j<filter[i].size(); j++) {
            MatType mat=randu<MatType>(cfg.kernelsize,cfg.kernelsize);
            *filter[i][j]=mat;
        }
    }
}

void ConvLayer::setinput(MatType** data)
{
    for(int i=0; i<indata.size(); i++){
        indata[i]=data[i];
    }
}

void ConvLayer::applyfilter()
{
    
    int r=cfg.inputrows-cfg.kernelsize+1;
    int c=cfg.inputcols-cfg.kernelsize+1;
    for(int i=0; i<cfg.noutmaps; i++){
        MatType temp(r,c);
        temp.zeros();
        for(int j=0; j<cfg.inmap[i].size();j++){
            temp += conv2(*indata[cfg.inmap[i][j]], *filter[i][j],"valid");
        }
        *outdata[i]=temp;
    }
}


void ConvLayer::downsample()
{
    for(int i=0; i<outdata.size();i++){
        *outdata[i]=maxpooling(*outdata[i], cfg.stride, cfg.side);
    }
}

void ConvLayer::run()
{
    applyfilter();
    downsample();
}

ConvLayer::~ConvLayer()
{
    for(int i=0; i<cfg.noutmaps; i++){
        delete outdata[i];
        for(int j=0; j<filter[i].size(); j++){
            delete filter[i][j];
        }
    }
}

FuLayer::FuLayer(int _inlength, int _outlength)
{
    inlen=_inlength;
    outlen=_outlength;
    weight=new MatType(outlen, inlen);
    outdata=new VecType(outlen);
}

FuLayer::~FuLayer()
{
    delete weight;
    delete outdata;
    indata=0;
    weight=0;
    outdata=0;
}

void FuLayer::setinput( VecType* _indata)
{
    indata=_indata;
}

void FuLayer::setweight( MatType* _mat)
{
    weight=_mat;
}

void FuLayer::run()
{
    *outdata=*weight*(*indata);
}

void FuLayer::print()
{
    cout<<"Info of FuLayer"<<endl;
    cout<<"inlen        "<<inlen<<endl;
    cout<<"outlen       "<<outlen<<endl;
    cout<<"weight       "<<"("<<weight->n_rows<<","<<weight->n_cols<<")"<<endl;
}

void FuLayer::randominit()
{
    *weight=randu<MatType>(outlen,inlen)/(inlen+outlen);
}


OutputLayer::OutputLayer()
{
    outdata=new VecType;
}

OutputLayer::~OutputLayer()
{
    delete outdata;
    outdata=0;
    indata =0;
}

void OutputLayer::setinput(VecType* _indata)
{
    indata=_indata;
}
void OutputLayer::run()
{
    ///TODO: ADD TYPES OF OPERATIONS, SOFTMAX,SIGMOID,RELU.
    ;
}


















