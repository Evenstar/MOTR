#define ARMA_DONT_USE_WRAPPER
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;
typedef fmat MatType;
MatType Conv2_Valid(const MatType& a, const MatType& b)
{
    long m=a.n_rows;
    long n=a.n_cols;
    long l1=b.n_rows;
    long l2=b.n_cols;
    MatType c(l1,l2);
    c.zeros();
    for(int i=0; i<l1; i++){
        for(int j=0; j<l2; j++){
            c(i,j)=b(l1-1-i,l2-1-j);
        }
    }
    MatType g(m-l1+1,n-l2+1);
    for (long k1=0; k1<m-l1+1;k1++){
        for (long k2=0; k2<n-l2+1; k2++){
            float s=0;
	               s=sum(sum(a.submat(k1,k2,k1+l1-1,k2+l2-1)%c));
            g(k1,k2)=s;
        }
    }
    return g;
}

int main(int argc, char** argv)
{
    MatType A = randu<MatType>(200,200);
    MatType B = randu<MatType>(7,7);
    for(int i=0; i<1000; i++)
      MatType C=Conv2_Valid(A,B);
    return 0;
}
