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

int main(int argc, char** argv)
{
    VecMatPtr ptr(new vector<MatType>);
    ptr->push_back(MatType(2,2));
    *(ptr->begin())<<1,2,3,4;
    ptr->push_back(MatType(2,2));
    (*ptr)[1]<<5,6,7,8;
    VecPtr vptr=Concatenate(ptr);
    cout<<(*vptr)<<endl;
    return 0;
}
