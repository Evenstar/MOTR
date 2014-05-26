//
//  Layer.h
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef CONVLAYER_H
#define CONVLAYER_H

#include "utils.h"

using namespace std;





class ConvLayer{
public:
    ConvLayer(){};
    
    ~ConvLayer(){};
    
    void SetFilter( const vector<FilterType> &) ;
    
    void SetIndata( vector<MatType>* );
    
    void SetReceiveset(const vector<set<int> >);
    
    void ApplyFilter();
    
    const vector<MatType>* input() const;
    
    const vector<MatType>* output() const;
    
public:
    
    vector<FilterType> filter;
    vector<MatType>* indata;
    vector<MatType>* outdata;
    LayerType layertype;
    vector<set<int> > receiveset;
    BoundaryType boundarytype;
    
    int stride;
    int side;
    int pooldim;
    
private:
    
    void ApplyNonlinearity( NonlinearityType );
    
    
    
};


#endif
