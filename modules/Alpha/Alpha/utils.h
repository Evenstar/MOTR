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
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv/cvaux.h>
#include "../Eigen/Dense"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

typedef Eigen::MatrixXf FilterType;
typedef Eigen::MatrixXf MatType;
typedef Eigen::VectorXf VecType;
typedef cv::Mat ImgType;
typedef boost::shared_ptr<std::vector<MatType> > VecMatPtr;
typedef boost::shared_ptr<MatType> MatPtr;
typedef boost::shared_ptr<VecType> VecPtr;
typedef boost::shared_ptr<std::vector<std::vector<FilterType> > > VecVecFilterPtr;
typedef boost::shared_ptr<std::vector<std::set<int> > > VecSetPtr;

#endif
