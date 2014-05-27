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
using namespace std;

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
    virtual void Downsample(){};
    virtual void ApplyNonlinearity(){};
};


class ConvLayer : public Layer{
public:
    ConvLayer(int _stride=0, int _side=0, int _kernelsize=0,
              int _ninmaps=0, int _noutmaps=0);
    ~ConvLayer(){};
public:
    
    void Setup(int _stride, int _side, int _kernelsize,
               int _ninmaps, int _noutmaps);
    
    void SetFilter( const vector<FilterType> &) ;
    
    void SetInput( vector<MatType>* );
    
    void SetReceiveset(const vector<set<int> > &);
    
    void ApplyFilter();
    
    void DownSample();
    
    void ApplyNonlinearity();
    
public:
    vector<FilterType> filter;
    vector<MatType>* indata;
    vector<MatType> outdata;
    vector<set<int> > receiveset;
    BoundaryType boundarytype;
    
    int stride;
    int side;
    int kernelsize;
    
    int ninmaps;
    int noutmaps;
    string name;

};

class FullyConnectedLayer : public Layer {
public:
    FullyConnectedLayer(int _stride=0, int _side=0,
                        int _fanin=0, int _fanout=0);
    ~FullyConnectedLayer(){};
    
public:
    void Setup(int _stride, int _side,
               int _fanin, int _fanout);

    void SetWeight( const MatType &);
    
    void SetInput( MatType *);
    
    void ApplyFilter();
    
    void ApplyNonlinearity();
    
    void DownSample();
    
public:
    
    MatType Weight;
    
    MatType* indata;     /// The input data.
    
    MatType outdata;
    
    int stride;
    int side;
    
    int fanin;
    int fanout;
    
    string name;
};




































#endif
