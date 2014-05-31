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
/**
 * @file
 * This is the definition for convolutional layers and fully connected layers.
 */
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
    
    /**
     * @file
     * @param _ninmaps Number of input maps.
     * @param _inputrows Number of rows of input matrix.
     * @param _inputcols Number of columns of input matrix.
     * @param _noutmaps Number of maps of this layer.
     * @param _stride stride.
     * @param _side side.
     * @param _kernelsize kernelsize, must be square.
     * @param _indata. Input data, optional.
     */
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
    
    vector<vector<FilterType> >filter;
    VecMatPtr indata;
    vector<MatType> outdata;
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
    
public:
    
    MatType Weight;
    
    MatPtr indata;     /// The input data.
    
    MatType outdata;
    
    int fanin;
    int fanout;
    
    string name;
};




































#endif
