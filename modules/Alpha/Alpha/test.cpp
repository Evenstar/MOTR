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

vector<MatType> Synthesize( ImgType img, int ncopies)
{
    vector<MatType> vec;
    MatType temp=Img2Mat(img);
    for (int i=0; i<ncopies; i++){
        vec.push_back(temp);
    }
    return vec;
}

void test_Synthesize(){
    ImgType img=LoadHepburn();
    vector<MatType> vec=Synthesize(img,5);
    for (int i=0; i<5;i++)
    {
        cout<<vec[i](0,0)<<endl;
    }
}


void test_Convlayer(){
    ConvLayer convlayer;
    convlayer.Setup(2,2,5,3,5);
    
    ImgType img=LoadHepburn();
    vector<MatType> vec=Synthesize(img,3);
    
    convlayer.SetInput(&vec);
    
    cout<<convlayer.stride<<" "<<convlayer.side<<" "<<convlayer.kernelsize<<endl;
    cout<<(*convlayer.indata)[0](0,0)<<endl;       ///A little odd.
}























