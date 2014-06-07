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

NetConfig mnistConfig(){
    NetConfig netconfig;
    
    vector<MatType>* xptr=new vector<MatType>;
    vector<MatType>* yptr=new vector<MatType>;
    ReadMnist(*xptr,*yptr);
    netconfig.nconvlayers=2;
    netconfig.indata=xptr;
    
    ConvConfig config;
    config.ninmaps=1;
    config.noutmaps=4;
    config.inputrows=28;
    config.inputcols=28;
    config.stride=2;
    config.side=2;
    config.kernelsize=5;
    for(int i=0; i<4; i++){
        set<int> temp;
        temp.insert(0);
        config.inmaps.push_back(temp);
    }
    vector<FilterType> z;
    for (int i=0; i<4; i++){
        z.clear();
        FilterType temp=FilterType::Random(5,5);
        z.push_back(temp);
        config.filter.push_back(z);
    }
    netconfig.convconfig.push_back(config);
    
    config.inmaps.clear();
    config.filter.clear();
    config.ninmaps=4;
    config.noutmaps=4;
    config.inputrows=12;
    config.inputcols=12;
    config.stride=2;
    config.side=2;
    config.kernelsize=5;
    for(int i=0; i<4; i++){
        set<int> temp;
        for(int j=0; j<4; j++){
            temp.insert(j);
        }
        config.inmaps.push_back(temp);
    }
    for (int i=0; i<4; i++){
        z.clear();
        for(int j=0;j<4;j++){
            FilterType temp=FilterType::Random(5,5);
            z.push_back(temp);
        }
        config.filter.push_back(z);
    }
    netconfig.convconfig.push_back(config);
    
    
    netconfig.nfulllayers=1;
    FullConfig fconfig;
    fconfig.fanin=64;
    fconfig.fanout=10;
    fconfig.weight=MatType::Random(fconfig.fanout,fconfig.fanin);
    netconfig.fullconfig.push_back(fconfig);
    
    return netconfig;
}
NetConfig generateNetConfig(){
    ImgType img=LoadHepburn();
    MatType temp=Img2Mat(img);
    temp=temp.block(100,100,200,200);
    
    NetConfig netconfig;
    netconfig.nconvlayers=2;
    netconfig.indata=new vector<MatType>;
    netconfig.indata->push_back(temp);
    
    ConvConfig config;
    config.ninmaps=1;
    config.noutmaps=5;
    config.inputrows=200;
    config.inputcols=200;
    config.stride=2;
    config.side=2;
    config.kernelsize=7;
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
    netconfig.convconfig.push_back(config);
    
    config.inmaps.clear();
    config.filter.clear();
    config.ninmaps=5;
    config.noutmaps=5;
    config.inputrows=97;
    config.inputcols=97;
    config.stride=2;
    config.side=2;
    config.kernelsize=7;
    for(int i=0; i<5; i++){
        set<int> temp;
        temp.insert(i);
        config.inmaps.push_back(temp);
    }
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
    netconfig.convconfig.push_back(config);
    
    netconfig.nfulllayers=2;
    FullConfig fconfig;
    fconfig.fanin=10125;
    fconfig.fanout=30;
    fconfig.weight=MatType::Random(fconfig.fanout,fconfig.fanin);
    netconfig.fullconfig.push_back(fconfig);
    
    fconfig.fanin=30;
    fconfig.fanout=10;
    fconfig.weight=MatType::Random(fconfig.fanout,fconfig.fanin);
    netconfig.fullconfig.push_back(fconfig);
    
    return netconfig;
}


void test_NetConfig(){
    NetConfig netconfig=mnistConfig();
    //netconfig.print();
    ConvNet convnet(netconfig);
//    convnet.print();
    convnet.run();
}


























