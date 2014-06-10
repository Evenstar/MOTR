
#include "convcore.h"
#include "utils.h"
#include "layer.h"
#include <iomanip>
using namespace std;
using namespace arma;

int main(int argc, char** argv)
{
//    InputConfig config(28,28,12,5,2,2);
//    InputLayer inputlayer(config);

    vector<MatType*> xtrain;
    vector<MatType*> ytrain;
    ReadMnistPtr(xtrain, ytrain,10);
    
    
    
    for(int i=0; i<xtrain.size();i++){
        delete xtrain[i];
        delete ytrain[i];
    }
    
    return 0;
}

