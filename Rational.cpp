#include "Rational.h"
#include "gcd.h"
#include "rational_exception.h"

//------------------------------------------------------------------------------
//constructor: (just ONE constructor -- uses default parameters)
Rational::Rational(int num, int denom):num(num),denom(denom){
  if(denom==0) {
    RationalException r("RationalException: can't instantiate Rational with denom 0");
    std::cout<<r.getWhat()<<endl;
    throw r;
  }
  int gcdx = gcd(this->num,this->denom);
  this->num=num/gcdx;
  this->denom=denom/gcdx;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//getters:
int Rational::getNumerator() const {return num;}
int Rational::getDenominator() const {return denom;}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//add & addInPlace:
Rational Rational::operator +(const Rational &a){
  return Rational(num * a.denom + a.num * denom, denom * a.denom);
}
Rational& Rational::operator +=(const Rational &a){
  int newNum = this->num*a.denom + a.num*this->denom;
  int newDenom = this->denom * a.denom;
  this->num = newNum/gcd(newNum,newDenom);
  this->denom = newDenom/gcd(newNum,newDenom);
  return *this;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//sub & subInPlace:
Rational Rational::operator -(const Rational &a){
  return Rational(num * a.denom - a.num * denom, denom * a.denom);
}
Rational& Rational::operator -=(const Rational &a){
  int newNum = this->num*a.denom - a.num*this->denom;
  int newDenom = this->denom * a.denom;
  this->num = newNum/gcd(newNum,newDenom);
  this->denom = newDenom/gcd(newNum,newDenom);
  return *this;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//mul & mulInPlace:
Rational Rational::operator *(const Rational &r){
  return Rational( this->num * (r.num), this->denom * (r.denom) );
}
Rational& Rational::operator *=(const Rational &r){
  this->num *= r.num;
  this->denom *= r.denom;
  return *this;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//div & divInPlace:
Rational Rational::operator /(const Rational &r){
  return Rational( this->num * (r.denom),this->denom * (r.num) );
}
Rational& Rational::operator /=(const Rational &r){
  this->num *= r.denom;
  this->denom *= r.num;
  return *this;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//else:
Rational Rational::neg() const{
  Rational r(-1*num,denom);
  return r;
}

Rational Rational::inv() const{
  if(num==0) {
    RationalException r("RationalException: can't instantiate Rational with denom 0");
    std::cout<<r.getWhat()<<endl;
    throw r;
  }
  int newNum=denom;
  int newDenom=num;
  Rational r(newNum,newDenom);
  return r;
}

bool Rational::equals(const Rational &r) const{
  double x = (float) (this->num) / (float) (this->denom);
  double y = (float) (r.num) / (float) (r.denom);
  return (x==y)? true: false;
}

int Rational::compareTo(const Rational &r) const{
  double x = (float) (this->num) / (float) (this->denom);
  double y = (float) (r.num) / (float) (r.denom);
  if(x>y) return 1;
  if(x<y) return -1;
  if(x==y) return 0;
}
//------------------------------------------------------------------------------

void Rational::print(std::ostream &os) const{
  if(this->denom!=1) os<<this->num<<"/"<<this->denom;
  else os<<this->num;
}
