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
#include <memory>
using namespace std;


class ConvLayer{
public:
    ConvLayer(const ConvConfig& config)
    {
        Initialize(config);
        interdata=new vector<MatType>;
        outdata=new vector<MatType>;
        interdata->reserve(noutmaps);
        outdata->reserve(noutmaps);
    }
    ~ConvLayer(){
    };
    
public:
    void run(){
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
    void print();
    
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



class FullLayer{
public:
    FullLayer(const FullConfig& _config)
    {
        fanin=_config.fanin;
        fanout=_config.fanout;
        weight=_config.weight;
        name="f";
        outdata=new MatType;
    };
    
    ~FullLayer(){};
    void run(){
        ApplyWeight();
    }
    void print();

    
    void SetInput( MatPtr );
    void ApplyWeight(){
        *outdata=weight*(*indata);
    }
    void ApplyNonlinearity(){
        *outdata=ApplyReLU(*outdata);
    }
    
public:
    int fanin;
    int fanout;
    string name;
    
    MatPtr indata;
    MatPtr outdata;
    MatType weight;
    
};


class InputLayer {
public:
    shared_ptr<MatType>  indata;
    shared_ptr<vector<shared_ptr<MatType> > > outdata;
    vector<vector<FilterType> > filter;
};























#endif
