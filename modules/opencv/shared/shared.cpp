#include <iostream>

using namespace std;

class A{
public:
  A(){};
  ~A(){};
  virtual void Do()=0;
};

class B: public A{
public:
  B(){};
  ~B(){};
  void Do();
};

void B::Do()
{
  cout<<"b";
}
int main()
{
  B b;
  return 0;

}
