//
//  convnet.cpp
//  Alpha
//
//  Created by ChengTai on 5/26/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "convnet.h"

    
MatType ConvNet::convert(vector<MatType> data)
{
    int n=data.size();
    int rows=data.begin()->rows();
    int cols=data.begin()->cols();
    int cnt=0;
    MatType mat(rows*cols*n,1);
    for(int i=0; i<n; i++){
        for(int j=0; j<rows; j++){
            for(int k=0; k<cols;k++){
                mat(cnt,0)=data[i](j,k);
                cnt++;
            }
        }
    }
    return mat;
}













    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
