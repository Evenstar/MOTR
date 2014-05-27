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

using namespace cv;
using namespace Eigen;



int main(int argc, char** argv)
{
    ConvLayer convlayer(2,2,5);
    test_Synthesize();
    return 0;
}
