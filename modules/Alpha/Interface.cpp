//
//  Interface.hpp
//  Alpha
//
//  Created by ChengTai on 6/2/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "utils.h"

typedef vector<MatType> DataType;

class ConvLayer{
    shared_ptr<DataType> run(shared_ptr<DataType>);
};

//Input is still regarded as matrix
class FullyConnectedLayer{
    shared_ptr<DataType> run(shared_ptr<DataType>);
};

class ConvNet{
    //construct layers of ConvLayers and Fully
    shared_ptr<DataType> run(shared_ptr<DataType>);
};

class Trainer{
    shared_ptr<ConvNet> run(shared_ptr<ConvNet>, DataType, DataType);
};