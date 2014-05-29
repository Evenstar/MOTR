//
//  test.cpp
//  Alpha
//
//  Created by ChengTai on 5/27/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "test.h"

/*

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
 


void test_Convlayer()
{
    ConvLayer convlayer(1,200,200,5,2,2,7);
    ImgType img=LoadHepburn();
    MatType mat=Img2Mat(img);
    mat=mat.block(100,100,200,200);
    vector<set<int> > _inmaps;
    for(int i=0; i<5; i++){
        set<int> temp;
        temp.insert(0);
        _inmaps.push_back(temp);
    }
    vector<MatType> insrc;
    insrc.push_back(mat);
    
    vector<vector<FilterType> > _filter;
    vector<FilterType> z;
    for (int i=0; i<5; i++){
        z.clear();
        FilterType temp=FilterType::Random(7,7);
        if (i==0)
        {
            temp=1.0/49.0*FilterType::Ones(7,7);
        }
        z.push_back(temp);
        _filter.push_back(z);
    }
    convlayer.SetInput(&insrc);
    convlayer.SetFilter(_filter);
    convlayer.SetInmaps(_inmaps);
    
    convlayer.ApplyFilter();
    cout<<convlayer.outdata.size()<<endl;
    cout<<convlayer.outdata[0].rows()<<convlayer.outdata[0].cols()<<endl;
    convlayer.DownSample();
    cout<<convlayer.outdata[0].rows()<<convlayer.outdata[0].cols()<<endl;
    convlayer.ApplyNonlinearity();
    cout<<convlayer.outdata[0].rows()<<convlayer.outdata[0].cols()<<endl;
    
    img=Mat2Img(convlayer.outdata[0]);
    namedWindow("Test", CV_WINDOW_AUTOSIZE);
    imshow("Test",img);
    waitKey(0);
    convlayer.SelfCheck();
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




void test_Configuration()
{
    /// Parameters of LeNet
    
    Configuration config;
    config.nconvlayers=2;
    config.ninputrows=28;
    config.ninputcols=28;
    config.kernelsize.push_back(5);
    config.kernelsize.push_back(5);
    config.stride.push_back(2);
    config.stride.push_back(2);
    config.side.push_back(2);
    config.side.push_back(2);
    config.nonlinearity.push_back("ReLU");
    config.nonlinearity.push_back("ReLU");
    config.isdownsample.push_back(true);
    config.isdownsample.push_back(true);
    config.nmaps.push_back(12);
    config.nmaps.push_back(12);
    config.objtype="L2";
    
    ///Set inmaps
    vector<set<int> > vec;
    for(int i=0; i<config.nmaps[0]; i++){
        set<int> temp;
        temp.insert(0);
        vec.push_back(temp);
    }
    config.inmaps.push_back(vec);
    vec.clear();
    for(int i=0; i<config.nmaps[1]; i++){
        set<int> temp;
        for(int j=0; j< config.nmaps[0];j++){
            temp.insert(j);
        }
        vec.push_back(temp);
    }
    config.inmaps.push_back(vec);
    config.ComputeSize();
    
    ///Set fully connected layers.
    config.nfclayers=2;
    config.nfcnodes.push_back(30);
    config.nfcnodes.push_back(10);
}
*/

void test_ConvNet()
{
    Config config1,config2,config3;
    config1.ninmaps=1;
    config1.inputrows=28;
    config1.inputcols=28;
    config1.stride=2;
    config1.side=2;
    config1.kernelsize=5;
    
    config1.ninmaps=1;
    config1.inputrows=12;
    config1.inputcols=12;
    config1.stride=2;
    config1.side=2;
    config1.kernelsize=5;
    
    config3.fanin=192;
    config3.fanout=10;
    
    Configuration configuration;
    configuration.nconvlayers=2;
    configuration.nfclayers=1;
    configuration.vconfig.push_back(config1);
    configuration.vconfig.push_back(config2);
    configuration.vconfig.push_back(config3);
    
    ConvNet convnet(configuration);
    convnet.Initialize();
    ConvLayer* ptr=dynamic_cast<ConvLayer*>(convnet.layer[0]);
    ptr->SelfCheck();
}























