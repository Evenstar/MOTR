//
//  layer.h
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef LAYER_H
#define LAYER_H
#include "utils.h"
#include "helper.h"
#include "configuration.h"
using namespace std;
using namespace boost;


class ConvLayer{
public:
    ConvLayer(const ConvConfig& config):
    interdata(new vector<MatType>)   {
        Initialize(config);
        interdata->reserve(noutmaps);
        outdata->reserve(noutmaps);
    }
    ~ConvLayer(){};
    
public:
    void run(){
            cout<<outdata->size()<<interdata->size()<<endl;
       // cout<<interdata->size()<<endl;
        ApplyFilter();
        DownSample();
        ApplyNonlinearity();
    }
    ///Just in case we want to modify the parameters.
    void SetFilter( const vector<vector<FilterType> >& _filter) {
        filter=_filter;
    }
    void SetInput( VecMatPtr _indata ){
        indata=_indata;
    }
    void SetInmaps( const vector<set<int> >& _inmaps){
        inmaps=_inmaps;
    }
    
    VecMatPtr Get(){
        return outdata;
    }
    
private:
    void ApplyFilter();
    void DownSample();
    void ApplyNonlinearity();
    bool SelfCheck();
    void Initialize(const ConvConfig& config){
        name        ="c";
        ninmaps     =config.ninmaps;
        inputrows   =config.inputrows;
        inputcols   =config.inputcols;
        noutmaps    =config.noutmaps;
        stride      =config.stride;
        side        =config.side;
        kernelsize  =config.kernelsize;
        indata      =config.indata;
        filter      =config.filter;
        inmaps      =config.inmaps;
    }
    
public:
    vector<vector<FilterType> > filter;
    VecMatPtr indata;
    VecMatPtr interdata;                ///data after convolution
    VecMatPtr outdata;                  ///output
    vector<set<int> > inmaps;
    
    string name;
    int ninmaps;
    int inputrows;
    int inputcols;
    
    int noutmaps;
    int stride;
    int side;
    int kernelsize;
};


/*
 class FullyConnectedLayer{
 public:
 FullyConnectedLayer(int _fanin, int _fanout):
 fanin(_fanin),fanout(_fanout){
 name="f";
 };
 
 FullyConnectedLayer(const Config& cfg):
 fanin(cfg.fanin),fanout(cfg.fanout){
 name="f";
 };
 
 ~FullyConnectedLayer(){};
 
 public:
 void Setup(int _stride, int _side,
 int _fanin, int _fanout);
 
 void SetWeight( MatPtr);
 
 void SetInput( MatPtr );
 
 void ApplyFilter();
 
 void ApplyNonlinearity();
 
 void DownSample();
 
 VecPtr Concatenate( VecMatPtr);
 public:
 
 MatPtr Weight;
 
 VecPtr indata;     /// The input data.
 
 VecPtr outdata;
 
 int fanin;
 int fanout;
 
 string name;
 };
 */
#endif
