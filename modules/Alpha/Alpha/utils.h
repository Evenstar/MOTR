//
//  utils.h
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>

#include "../Eigen/Dense"

enum LayerType {Convolution, FullyConnected};
enum BoundaryType {Valid, Full};
enum NonlinearityType {Sigmoid, ReLU};

typedef Eigen::MatrixXf FilterType;
typedef Eigen::MatrixXf MatType;
typedef float ScalarType;
#endif
