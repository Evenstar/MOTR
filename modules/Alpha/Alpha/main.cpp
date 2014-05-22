//
//  main.cpp
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//


#include "convlayer.h"
#include "helper.h"
using Eigen::MatrixXd;
int main(int argc, char** argv)
{
    vector<FilterType> filter;
    LoadFilter(filter, "/Users/chengtai/Documents/2014/topics2014/Alpha/data/filter.txt");
    //LoadFilter(filter, "../data/filter.txt");
    return 0;
}
