//
//  convcore.h
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef CONVCORE_H
#define CONVCORE_H
#include "stdafx.h"
using namespace std;
MatType Conv2_Valid(const MatType& a, const MatType& b);
MatType Conv2(const MatType& a, const MatType& b, string boundarytype);


#endif
