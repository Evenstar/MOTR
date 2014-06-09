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

    // insert code here...
    shared_ptr<int> a(new int);
    *a=1;
    cout<<*a<<endl;
    MatType b=MatType::Random(3,3);
    cout<<b<<endl;
    return 0;
}

