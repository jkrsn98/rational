#include "Rational.h"
#include <iostream>

using namespace std;

int main(){
  Rational r1(3,6);
  Rational r2(1,2);

  Rational r3 = r1+r2;
  std::cout<<r3<<endl;


  return 0;
}
