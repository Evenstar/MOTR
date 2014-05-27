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
using namespace std;
using namespace cv;
using namespace Eigen;

ImgType LoadHepburn();

vector<MatType> Synthesize( ImgType img, int ncopies);



void test_Synthesize();


void test_Convlayer();


void test_GenerateRandomFilter();

#endif /* defined(__Alpha__test__) */
