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




void test_GenerateRandomFilter()
{
    vector<FilterType> filter=GenerateRandomFilter(3,5,5);
    cout<<filter.size()<<endl;
    cout<<filter[0]<<endl;
}


void test_Convlayer(){
    ConvLayer convlayer;
    convlayer.Setup(2,2,5,3,5);
    
    ImgType img=LoadHepburn();
    vector<MatType> vec=Synthesize(img,3);
    
    convlayer.SetInput(&vec);
    
    cout<<convlayer.stride<<" "<<convlayer.side<<" "<<convlayer.kernelsize<<endl;
    cout<<(*convlayer.indata)[0](0,0)<<endl;       ///A little odd.
    
    vector<FilterType> _filter=GenerateRandomFilter(3,5,5);
    _filter[0]=1.0/25.0*FilterType::Ones(5,5);
    convlayer.SetFilter(_filter);

    cout<<convlayer.filter.size()<<endl;
    cout<<convlayer.filter[0]<<endl;
    
    convlayer.ApplyFilter();
    
    convlayer.DownSample();

    convlayer.ApplyNonlinearity();
    
    MatType mat=convlayer.outdata[4];
    namedWindow("Filter",CV_WINDOW_AUTOSIZE);
    imshow("Filter",Mat2Img(mat));
    waitKey(0);
}


void test_MaxPooling()
{
    ImgType img=LoadHepburn();
    MatType mat=MaxPooling(Img2Mat(img),2,2);
    namedWindow("Filter",CV_WINDOW_AUTOSIZE);
    imshow("Filter",Mat2Img(mat));
    waitKey(0);
}

void test_ApplyReLU()
{
    ImgType img=LoadHepburn();
    MatType mat=ApplyReLU(Img2Mat(img));
    namedWindow("Filter",CV_WINDOW_AUTOSIZE);
    imshow("Filter",Mat2Img(mat));
    waitKey(0);
}


void test_FullyConnectedLayer()
{
    FullyConnectedLayer fclayer;
    fclayer.Setup(2,2,500,10);
    fclayer.SetWeight(GenerateRandomWeights(fclayer.fanout,fclayer.fanin));
    ImgType img=LoadHepburn();
    MatType mat=Img2Mat(img);
    fclayer.SetInput(&mat);
    fclayer.ApplyFilter();
    fclayer.ApplyNonlinearity();
}






























