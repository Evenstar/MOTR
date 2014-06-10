//
//  utils.cpp
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "utils.h"


int ReverseInt (int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1=i&255;
    ch2=(i>>8)&255;
    ch3=(i>>16)&255;
    ch4=(i>>24)&255;
    return((int)ch1<<24)+((int)ch2<<16)+((int)ch3<<8)+ch4;
}

int ReverseInt (int i);
void ReadMnistPtr(vector<MatType*>& xtrain,
                  vector<MatType*>& ytrain,
                  int NUMBER)
{
    string prefix("/Users/chengtai/Documents/2014/MOTR/modules/beta/data/mnist");
    ifstream file;
    string filename=prefix+string("/train-images-idx3-ubyte");
    file.open(filename.c_str(), ios::binary);
    int magicnumber=2051;
    int nimages=60000;
    int rows=28;
    int cols=28;
    unsigned char temp;
    
    file.read((char*)&magicnumber,sizeof(magicnumber));
    magicnumber=ReverseInt(magicnumber);
    if (magicnumber!=2051){
        cout<<"Error while reading mnist."<<endl;
        exit(-1);
    }
    file.read((char*)&nimages,sizeof(int));
    file.read((char*)&rows,sizeof(int));
    file.read((char*)&cols,sizeof(int));
    
    for(int k=0; k<NUMBER; k++){
        MatType* z=new MatType(28,28);
        for(int i=0; i<28;i++){
            for(int j=0;j<28;j++){
                file.read((char*)&temp, sizeof(temp));
                (*z)(i,j)=(float)temp/255.0;
            }
        }
        xtrain.push_back(z);
    }
    file.close();
    
    
    filename=prefix+string("/train-labels-idx1-ubyte");
    file.open(filename.c_str(),ios::binary);
    file.read((char*)&magicnumber,sizeof(magicnumber));
    magicnumber=ReverseInt(magicnumber);
    if (magicnumber!=2049){
        cout<<"Error while reading mnist."<<endl;
        exit(-1);
    }
    file.read((char*)&nimages,sizeof(int));
    
    for(int i=0 ;i<NUMBER;i++){
        MatType* z=new MatType(10,1);
        file.read((char*)&temp,sizeof(temp));
        (*z)((int)temp,0)=1;
        ytrain.push_back(z);
    }
    file.close();
}

