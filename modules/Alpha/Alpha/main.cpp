//
//  main.cpp
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//


#include "layer.h"
#include "helper.h"
#include "visual.h"
#include "convnet.h"
#include "test.h"

int main(int argc, char** argv)
{
    vector<MatType> xtrain;
    vector<MatType> ytrain;
    ReadMnist(xtrain,ytrain);
    cout<<xtrain[30]<<endl;
    return 0;
}
