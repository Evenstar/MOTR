//
//  Header.h
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef UTILS_H
#define UTILS_H

#include "stdafx.h"

///Load part of the data of the mnist dataset.
void ReadMnistPtr(vector<MatType*>& xtrain,
                  vector<MatType*>& ytrain,
                  int NUMBER=1);

#endif
