//
//  main.cpp
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//


#include "layer.h"
#include "helper.h"
#include "visual.h"
#include "convnet.h"
#include "test.h"

using namespace cv;
using namespace Eigen;
using namespace std;
using namespace boost;
#include <memory>
int main(int argc, char** argv)
{
    shared_ptr<string> p(new string("123"));
    shared_ptr<string> p2(new string("456"));
    p.swap(p2);
    cout<<p.use_count()<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;

    test_ConvNet();
    return 0;
}
