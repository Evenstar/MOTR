//
//  main.cpp
//  beta
//
//  Created by ChengTai on 6/9/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "layer.h"

using namespace std;
int main(int argc, const char * argv[])
{
    InputConfig config(28,28,12,5,2,2);
    InputLayer layer0(config);
    layer0.Print();
    cout<<layer0.outdata.empty()<<endl;
    
    return 0;
}

