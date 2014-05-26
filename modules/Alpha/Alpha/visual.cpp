//
//  visual.cpp
//  Alpha
//
//  Created by ChengTai on 5/23/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "visual.h"
using namespace cv;


 void ReadImage(cv::Mat& I, int argc, char** argv)
{
    if ( argc==3 && !strcmp(argv[2],"G")){
        I=imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    } else {
        I=imread(argv[1], CV_LOAD_IMAGE_COLOR);
    }
}
