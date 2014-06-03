//
//  test.cpp
//  Alpha
//
//  Created by ChengTai on 5/27/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "test.h"



ImgType LoadHepburn()
{
    ImgType img;
    string fname("/Users/chengtai/Documents/2014/MOTR/modules/Alpha/data/hepburn.jpg");
    img=imread(fname, CV_LOAD_IMAGE_GRAYSCALE);
    img.convertTo(img,CV_32F);
    normalize(img,img,0,1,cv::NORM_MINMAX, CV_32F);
    return img;
}


void test_ConvLayer()
{
    ConvConfig config;
    config.ninmaps=1;
    config.noutmaps=5;
    config.inputrows=200;
    config.inputcols=200;
    config.stride=2;
    config.side=2;
    config.kernelsize=7;
    ImgType img=LoadHepburn();
    VecMatPtr matptr(make_shared<vector<MatType> >());
    MatType temp=Img2Mat(img);
    temp=temp.block(100,100,200,200);
    matptr->push_back(temp);
    config.indata=matptr;
    for(int i=0; i<5; i++){
        set<int> temp;
        temp.insert(0);
        config.inmaps.push_back(temp);
    }
    vector<FilterType> z;
    for (int i=0; i<5; i++){
        z.clear();
        FilterType temp=FilterType::Random(7,7);
        if (i==0)
        {
            temp=1.0/49.0*FilterType::Ones(7,7);
        }
        z.push_back(temp);
        config.filter.push_back(z);
    }
    
    ConvLayer convlayer(config);
     convlayer.run();
    
    //img=Mat2Img((*convlayer.outdata)[0]);
   // namedWindow("Test", CV_WINDOW_AUTOSIZE);
   // imshow("Test",img);
   // waitKey(0);
     
}
































