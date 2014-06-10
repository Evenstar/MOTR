
#include "convcore.h"
#include "utils.h"
#include "layer.h"
#include <iomanip>
using namespace std;
using namespace arma;

_INITIALIZE_EASYLOGGINGPP

int main(int argc, char** argv)
{
    InputConfig config(28,28,12,5,2,2);
    InputLayer inputlayer(config);
    ConvlayerConfig convcfg(28,28,4,5,2,2,8,2);
    ConvLayer convlayer(convcfg);
    convlayer.print();
    convlayer.randominit();
    convlayer.print();
    //
    //    vector<MatType*> xtrain;
    //    vector<MatType*> ytrain;
    //    readmnist(xtrain, ytrain,6000);
    //    inputlayer.setinput(xtrain[2]);
    //
    //    for(int i=0; i<12;i++){
    //        MatType m(5,5);
    //        if (i!=0){
    //         m=randu<MatType>(5,5);
    //        }else{
    //            m=m.ones()/25;
    //        }
    //        inputlayer.setfilter(m,i);
    //    }
    //    inputlayer.run();
    //
    //     MatType** ptr=inputlayer.data();
    //
    //    cout<<*ptr[1]<<endl;
    //    for(int i=0; i<xtrain.size();i++){
    //        delete xtrain[i];
    //        delete ytrain[i];
    //    }
    //    MatType A=randu<MatType>(280,280);
    //    for(int i=0; i<1000;i++)
    //    MatType B=maxpooling(A,2,2);
    //
    return 0;
}

