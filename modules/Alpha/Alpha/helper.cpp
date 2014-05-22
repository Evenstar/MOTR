//
//  helper.cpp
//  Alpha
//
//  Created by ChengTai on 5/22/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#include "utils.h"
using namespace std;
void LoadFilter(vector<FilterType>& filter, string fname)
{
    ifstream fin(fname.c_str());
    if (!fin){
        cerr<<"Cannot load filter."<<endl;
    }
    int m, r;
    fin>>m>>r;
    filter.clear();
    for(int i=0; i<m; i++){
        FilterType a(r,r);
        for(int j=0; j<r*r; j++){
            fin>>a(j-r*(j/r),j/r);
        }
        cout<<a<<endl;
        filter.push_back(a);
    }
    fin.close();
}
