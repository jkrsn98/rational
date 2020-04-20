#include "Rational.h"
#include <iostream>

using namespace std;

int main(){
  Rational r1(3,6);
  Rational r2(1,2);

  cout<<"Rational r1: "<<r1<<endl<<"Rational r2: "<<r2<<endl;
  cout<<"r1.add(r2): " << r1.add(r2)<<endl;;
  cout<<"Rational r1: "<<r1<<endl<<"Rational r2: "<<r2<<endl;
  cout<<"---------------"<<endl;
  cout<<"r1.addInPlace(r2): " << r1.addInPlace(r2)<<endl;;
  cout<<"Rational r1: "<<r1<<endl<<"Rational r2: "<<r2<<endl;


  return 0;
}
