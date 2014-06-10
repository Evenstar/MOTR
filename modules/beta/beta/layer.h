//
//  layer.h
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef LAYER_H
#define LAYER_H
#include "stdafx.h"


using namespace std;

class InputConfig{
public:
    InputConfig(int _inputrows=0, int _inputcols=0,
                int _noutmaps=0, int _kernelsize=0,
                int _stride=0, int _side=0):
    inputrows(_inputrows),inputcols(_inputcols),
    noutmaps(_noutmaps), kernelsize(_kernelsize),
    stride(_stride),side(_side){};
public:
    int inputrows;
    int inputcols;
    int noutmaps;
    int kernelsize;
    int stride;
    int side;
    void print();
};


class InputLayer {
public:
    InputLayer(const InputConfig& _cfg);
    ~InputLayer();
    inline void setinput(MatType* ptr){
        indata=ptr;
    }
    
    ///to avoid memory error, data copy is involved.
    void setfilter(const vector<MatType*> &);
    
    void setfilter(const MatType&, int);
    
    void print();
    
    void run();
    
    ///return the data ptr, dangerous, only used for initialization of next layer.
    MatType** data() { return &outdata[0]; }
private:
    MatType*  indata;
    vector<MatType*> outdata;
    vector<MatType*> filter;
    InputConfig cfg;
    
private:
    void applyfilter();
    void downsample();
};


class ConvlayerConfig : public InputConfig {
public:
    ConvlayerConfig(int _inputrows=0, int _inputcols=0,
                    int _noutmaps=0, int _kernelsize=0,
                    int _stride=0, int _side=0,
                    int _ninmaps=0, int _permaps=0):
    InputConfig(_inputrows,_inputcols,_noutmaps,
                _kernelsize,_stride,_side), ninmaps(_ninmaps),permaps(_permaps)
    {
        setdefaultinmaps();
    }
    
    int ninmaps;
    int permaps;
    vector<vector<int> > inmap;
    void print();
private:
    void setdefaultinmaps();
};

class ConvLayer {
public:
    ConvLayer(const ConvlayerConfig& _cfg);
    
    void print();
    
    void setfilter(const MatType&, int i, int j);
    
    void setfilter(const vector<vector<MatType*> >& _filter);
    
    void randominit();
    
private:
    vector<MatType*> indata;
    vector<MatType*> outdata;
    vector<vector<MatType*> > filter;
    ConvlayerConfig cfg;
};





#endif
