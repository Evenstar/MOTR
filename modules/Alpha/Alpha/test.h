//
//  test.h
//  Alpha
//
//  Created by ChengTai on 5/27/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef TEST_H
#define TEST_H
#include "utils.h"
#include "helper.h"
#include "visual.h"
#include "layer.h"
#include "convnet.h"
#include "configuration.h"
using namespace std;
using namespace cv;
using namespace Eigen;

ImgType LoadHepburn();

void test_ConvNet();

void test_NetConfig();

NetConfig generateNetConfig();


NetConfig mnistConfig();























#endif /* defined(__Alpha__test__) */
