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
#include <ctime>
#include <memory>
using namespace std;



int main(int argc, char** argv)
{
    
    vector<shared_ptr<MatType> > xtrain;
    vector<shared_ptr<MatType> > ytrain;
    ReadMnistPtr(xtrain,ytrain,1000);
    return 0;
}
