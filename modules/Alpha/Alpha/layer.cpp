//
//  convlayer.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "layer.h"


///TODO: the index order is filter[j][i], inmaps[j][i], not the other way around.
void ConvLayer::ApplyFilter()
{
    if (!interdata->empty()){
        interdata->clear();
    }
    for (int j=0; j<noutmaps; j++){
        MatType z=MatType::Zero(inputrows-kernelsize+1, inputcols-kernelsize+1);
        for (int i=0; i<inmaps[j].size();i++){
            MatType temp=Conv2((*indata)[i],filter[j][i],"valid");
            z+=temp;
        }
        interdata->push_back(z);
    }
}


void ConvLayer::DownSample()
{
    if(!outdata->empty()){
        outdata->clear();
    }
    for (int i=0; i<interdata->size(); i++){
        MatType temp=MaxPooling((*interdata)[i],stride,side);
        outdata->push_back(temp);
    }
}

void ConvLayer::ApplyNonlinearity(){
    for (int i=0; i<outdata->size(); i++){
        MatType mat=(*outdata)[i];
        (*outdata)[i]=ApplyReLU(mat);
    }
}


void ConvLayer::print(){
    cout<<"ninmaps      "<<ninmaps<<endl;
    cout<<"inputrows    "<<inputrows<<endl;
    cout<<"inputcols    "<<inputcols<<endl;
    cout<<"noutmaps     "<<noutmaps<<endl;
    cout<<"stride       "<<stride<<endl;
    cout<<"side         "<<side<<endl;
    cout<<"kernelsize   "<<kernelsize<<endl;
    
    if(indata->empty()){
        cout<<"indata       empty"<<endl;
    } else {
        cout<<"indata       ";
        printVector(indata);
    }
    if(interdata->empty()){
        cout<<"interdata    empty"<<endl;
    } else {
        cout<<"interdata    ";
        printVector(interdata);
    }
    if(outdata->empty()){
        cout<<"outdata      empty"<<endl;
    } else {
        cout<<"outdata      ";
        printVector(outdata);
    }
    displayVector(outdata);
}

void FullLayer::print(){
    cout<<"fanin        "<<fanin<<endl;
    cout<<"fanout       "<<fanout<<endl;
    if (!indata){
        cout<<"indata        empty"<<endl;
    } else {
        cout<<"indata       "<<"("<<indata->rows()<<","<<indata->cols()<<")"<<endl;
    }
    if (!outdata){
        cout<<"indata        empty"<<endl;
    } else {
        cout<<"outdata      "<<"("<<outdata->rows()<<","<<outdata->cols()<<")"<<endl;
    }
}






