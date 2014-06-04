//
//  trainsgd.h
//  Alpha
//
//  Created by ChengTai on 6/3/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef TRAINSGD_H
#define TRAINSGD_H

#include "utils.h"
#include "convnet.h"
class TrainSGD{
    TrainSGD();
    ~TrainSGD();
    
    void LoadTrainingData();
    void ComputeGrad(ConvNet& convnet);
    void ApplyGrad(ConvNet& convnet);
    
    float TrainingError();
    float TestingError();
    
    void run();
public:
    VecMatPtr xtrain;
    VecMatPtr ytrain;
    vector<vector<FilterType> > filtergrad;
    vector<MatType> weightgrad;
    
    //for monitoring only.
    VecMatPtr xtest;
    VecMatPtr ytest;
    
    //parameters
    int batchsize;
    int nepoches;
    float learningrate;
};

#endif
