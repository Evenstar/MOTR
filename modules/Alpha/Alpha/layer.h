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


class Layer{
public:
    Layer(){};
    virtual ~Layer(){};
    
public:
    virtual void ApplyFilter(){};
    virtual void ApplyNonlinearity(){};
};


class ConvLayer : public Layer{
public:
    
    ConvLayer(int _ninmaps, int _inputrows, int _inputcols,
              int _noutmaps, int _stride, int _side,
              int _kernelsize)
    :ninmaps(_ninmaps), inputrows(_inputrows),
    inputcols(_inputcols),noutmaps(_noutmaps),
    stride(_stride), side(_side), kernelsize(_kernelsize)
    {
        name="c";
    }
    
    ConvLayer(const Config& cfg):
    ninmaps(cfg.ninmaps),inputrows(cfg.inputrows),inputcols(cfg.inputcols),
    noutmaps(cfg.noutmaps),stride(cfg.stride),side(cfg.side),kernelsize(cfg.kernelsize)
    {
        name="c";
    }
    
    ~ConvLayer(){};
    
public:
    void SetFilter( const vector<vector<FilterType> >&) ;
    void SetInput( VecMatPtr _indata );
    void SetInmaps(const vector<set<int> > &);
    void ApplyFilter();
    void DownSample();
    void ApplyNonlinearity();
    bool SelfCheck();
    
public:
    VecVecFilterPtr filter;
    VecMatPtr indata;
    VecMatPtr outdata;
    VecSetPtr inmaps;
    
    string name;
    int ninmaps;
    int inputrows;
    int inputcols;
    
    int noutmaps;
    int stride;
    int side;
    int kernelsize;
};



class FullyConnectedLayer : public Layer {
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
    
    void SetWeight( const MatType &);
    
    void SetInput( MatPtr);
    
    void ApplyFilter();
    
    void ApplyNonlinearity();
    
    void DownSample();
    
    VecPtr Concatenate( VecMatPtr);
public:
    
    MatPtr Weight;
    
    MatPtr indata;     /// The input data.
    
    MatPtr outdata;
    
    int fanin;
    int fanout;
    
    string name;
};

#endif
