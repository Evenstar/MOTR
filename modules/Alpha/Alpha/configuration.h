//
//  Configuration.h
//  Alpha
//
//  Created by ChengTai on 5/28/14.
//  Copyright (c) 2014 ChengTai. All rights reserved.
//

#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "utils.h"
using namespace std;
struct FullConfig{
    int fanin;
    int fanout;
    MatType weight;
    void print(){
        cout<<"fanin        "<<fanin<<endl;
        cout<<"fanout       "<<fanout<<endl;
        cout<<"weight       "<<"("<<weight.rows()<<","<<weight.cols()<<")"<<endl;
    }
};

struct ConvConfig{
    int ninmaps;
    int inputrows;
    int inputcols;
    int stride;
    int side;
    int kernelsize;
    int noutmaps;
    vector<set<int> > inmaps;
    vector<vector<FilterType> > filter;
    void print(){
        cout<<"ninmaps      "<<ninmaps<<endl;
        cout<<"inputrows    "<<inputrows<<endl;
        cout<<"inputcols    "<<inputcols<<endl;
        cout<<"noutmaps     "<<noutmaps<<endl;
        cout<<"stride       "<<stride<<endl;
        cout<<"side         "<<side<<endl;
        cout<<"kernelsize   "<<kernelsize<<endl;
        
        if (inmaps.empty()){
            cout<<"inmaps   empty"<<endl;
        } else {
            cout<<"inmaps       {";
            for(int i=0; i<inmaps.size();i++){
                cout<<"(";
                for(set<int>::iterator it=inmaps[i].begin(); it!=inmaps[i].end();it++){
                    cout<<(*it)<<",";
                }
                cout<<"),";
            }
            cout<<"}"<<endl;
        }
        
        if(filter.empty()){
            cout<<"filter       empty"<<endl;
        } else {
            cout<<"filter       {";
            for(int j=0; j<filter.size();j++){
                cout<<"[";
                for(int i=0; i<filter[j].size(); i++){
                    cout<<"("<<filter[j][i].rows()<<","<<filter[j][i].cols()<<")";
                }
                cout<<"],";
            }
            cout<<"}"<<endl;
        }
    }
};

struct NetConfig{
    VecMatPtr indata;
    int nconvlayers;
    vector<ConvConfig> convconfig;
    int nfulllayers;
    vector<FullConfig> fullconfig;
    
    void print(){
        cout<<"Summary of NetConfig"<<endl;
        if (indata->empty()){
            cout<<"Input    empty"<<endl;
        } else {
            cout<<"Input        ";
            printVector(indata);
        }
        
        cout<<"nconvlayers  "<<nconvlayers<<endl;
        for(int i=0; i<nconvlayers; i++){
            cout<<"ConvLayer "<<i<<"    "<<endl;
            convconfig[i].print();
        }
        cout<<"nfulllayers  "<<nfulllayers<<endl;
        for(int i=0;i<nfulllayers; i++){
            cout<<"FullLayer    "<<i<<" "<<endl;
            fullconfig[i].print();
        }
    }
};
#endif
