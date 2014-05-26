//
//  main.cpp
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//


#include "convlayer.h"
#include "helper.h"
#include "visual.h"
using Eigen::MatrixXf;
using Eigen::MatrixXi;
using namespace cv;
ImgType test(int argc, char** argv)
{
    ImgType img;
    ReadImage(img,argc,argv);
    img.convertTo(img,CV_32F);
    normalize(img,img,0,1,cv::NORM_MINMAX, CV_32F);
    //namedWindow("gray",CV_WINDOW_AUTOSIZE);
    //imshow("gray", img);
    //waitKey(0);
    return img;
}


int main(int argc, char** argv)
{
    vector<FilterType> filter;
    LoadFilter(filter, "/Users/chengtai/Documents/2014/MOTR/modules/Alpha/data/filter.txt");
    //test(argc,argv);
   
    ConvLayer convlayer;
    convlayer.SetFilter(filter);
    
    vector<FilterType> it=convlayer.filter;
    for (int i=0; i<1;i++)
    {
        cout<<it[i]<<endl;
    }
    Mat img=test(argc,argv);
    MatType mat=Img2Mat(img);
    //LoadFilter(filter, "../data/filter.txt");
    cout<<mat<<endl;
    return 0;
}
