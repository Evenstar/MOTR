
#include "convcore.h"
#include "utils.h"
#include "layer.h"
#include <iomanip>
using namespace std;
using namespace arma;

_INITIALIZE_EASYLOGGINGPP

int main(int argc, char** argv)
{
//    InputConfig config(28,28,4,5,2,2);
//    InputLayer inputlayer(config);
//
//    
//    vector<MatType*> xtrain;
//    vector<MatType*> ytrain;
//    readmnist(xtrain, ytrain,6000);
//    inputlayer.setinput(xtrain[1]);
//    inputlayer.randominit();
//    inputlayer.setfilter(ones(5,5)/25.0,0);
//    inputlayer.run();
//    MatType** ptr=inputlayer.data();
//    cout<<*ptr[0]<<endl;
//    
//    ConvlayerConfig convcfg(12,12,8,5,2,2,4,1);
//    ConvLayer convlayer(convcfg);
//    convlayer.randominit();
//    convlayer.setinput(inputlayer.data());
//    convlayer.run();
//    
//    ptr=convlayer.data();
//    cout<<*ptr[0]<<endl;
//    
//    for(int i=0; i<xtrain.size();i++){
//        delete xtrain[i];
//        delete ytrain[i];
//    }
//    
    FuLayer flayer(10,5);
    VecType vec=randu<VecType>(10);
    flayer.randominit();
    flayer.setinput(&vec);
    flayer.print();
    flayer.run();
    VecType* ptr=flayer.data();
    cout<<*ptr<<endl;
    return 0;
}

