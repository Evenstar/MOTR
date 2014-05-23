//
//  main.cpp
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//


#include "convlayer.h"
#include "helper.h"
using Eigen::MatrixXf;
using Eigen::MatrixXi;

void test(){
    Eigen::MatrixXf a(4,4);
    a <<  1, 2, 3, 4,
    5, 6, 7, 8,
    9,10,11,12,
    13,14,15,16;

Eigen::MatrixXf b(3,3);
    b << 1,2,3,4,5,6,7,8,9;
    MatType d=Conv2(a,b,Full);
    cout<<d<<endl;
}
int main(int argc, char** argv)
{
    vector<FilterType> filter;
    //LoadFilter(filter, "/Users/chengtai/Documents/2014/topics2014/Alpha/data/filter.txt");
    test();
    //LoadFilter(filter, "../data/filter.txt");
    return 0;
}
