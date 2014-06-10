
#include "convcore.h"
#include "utils.h"
#include "layer.h"
#include <iomanip>
using namespace std;
using namespace arma;

_INITIALIZE_EASYLOGGINGPP

int main(int argc, char** argv)
{
    InputConfig config(28,28,4,5,2,2);
    InputLayer inputlayer(config);

    
    vector<MatType*> xtrain;
    vector<MatType*> ytrain;
    readmnist(xtrain, ytrain,6000);
    inputlayer.setinput(xtrain[1]);

    for(int i=0; i<4;i++){
        MatType m(5,5);
        if (i!=0){
         m=randu<MatType>(5,5);
        }else{
            m=m.ones()/25;
        }
        inputlayer.setfilter(m,i);
    }
    inputlayer.run();

    ConvlayerConfig convcfg(28,28,4,5,2,2,8,2);
    ConvLayer convlayer(convcfg);
    convlayer.randominit();
    convlayer.setinput(inputlayer.data());
    convlayer.applyfilter();
//    cout<<*convlayer.outdata[0]<<endl;
    for(int i=0; i<xtrain.size();i++){
        delete xtrain[i];
        delete ytrain[i];
    }
    

    return 0;
}

