#include <iostream>
#include <armadillo>
#include "convcore.h"
using namespace std;
using namespace arma;

int main(int argc, char** argv)
{
    MatType A = randu<MatType>(28,28);
    mat55 B= randu<MatType>(5,5);
    //    for(int i=0; i<1000; i++)
    //        MatType C=Conv2_Valid(A,B);
    for(int i=0; i<100000; i++)
        MatType C=Conv2(A,B,"valid");
    return 0;
}

