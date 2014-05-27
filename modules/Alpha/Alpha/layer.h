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
using namespace std;

/**
 * @file 
 * This is the definition for convolutional layers and fully connected layers.
 */
class Layer{
public:
    Layer(){};
    virtual ~Layer();
    
public:
    
    string name;
    
public:
    virtual void ApplyFilter();
    virtual void Downsample();
    virtual void ApplyNonlinearity();
    
    
};


class ConvLayer : public Layer{
public:
    ConvLayer(){};
    ~ConvLayer(){};
public:
    void SetFilter( const vector<FilterType> &) ;
    
    void SetInput( vector<MatType>* );
    
    void SetReceiveset(const vector<set<int> >);
    
    void ApplyFilter();
    
    void DownSample();
    
    void ApplyNonlinearity();
    
    vector<MatType>* output();
    
public:
    vector<FilterType> filter;
    vector<MatType>* indata;
    vector<MatType>* outdata;
    vector<set<int> > receiveset;
    BoundaryType boundarytype;
    
    int stride;
    int side;
    int pooldim;

};

class FullyConnectedLayer : public Layer {
public:
    FullyConnectedLayer(){};
    ~FullyConnectedLayer(){};
    
public:

    void SetWeight( const MatType &);
    
    void SetInput(const MatType &);
    
    void ApplyFilter();
    
    void ApplyNonlinearity();
    
    void DownSample();
    
    void SetInput(MatType*);
    
public:
    
    MatType Weight;
    
    MatType* indata;     /// The input data.
    
    MatType* outdata;
    
    int stride;
    int side;
    int pooldim;
    
    
};




































#endif
