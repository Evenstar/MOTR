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
    NetConfig mnistconfig=mnistConfig();
    mnistconfig.print();
    ConvNet convnet(mnistconfig);
//    convnet.print();
    convnet.run();
    return 0;
}
