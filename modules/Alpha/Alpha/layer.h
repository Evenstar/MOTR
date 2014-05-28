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
    virtual void ApplyNonlinearity(){};
};


class ConvLayer : public Layer{
public:
    
    /**
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
              int _kernelsize, vector<MatType>* _indata=NULL)
    :ninmaps(_ninmaps), inputrows(_inputrows),
    inputcols(_inputcols),noutmaps(_noutmaps),
    stride(_stride), side(_side), kernelsize(_kernelsize)
    {
        if (!(_indata==NULL)){
            SetInput(_indata);
        }
    }
    
    
    ~ConvLayer(){};
public:
    
    void SetFilter( const vector<vector<FilterType> >&) ;
    
    void SetInput( vector<MatType>* );
    
    void SetInmaps(const vector<set<int> > &);
    
    void ApplyFilter();
    
    void DownSample();
    
    void ApplyNonlinearity();
    
    bool SelfCheck();
    
public:
    
    vector<vector<FilterType> >filter;
    vector<MatType>* indata;
    vector<MatType> outdata;
    vector<set<int> > inmaps;
    
    string name;
    const int ninmaps;
    const int inputrows;
    const int inputcols;
    
    const int noutmaps;
    const int stride;
    const int side;
    const int kernelsize;
    
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
