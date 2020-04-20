#include "Rational.h"
#include "gcd.h"

//---------------
//constructors
//---------------
Rational::Rational():num(0), denom(0){}
Rational::Rational(int num):num(num), denom(1){}
Rational::Rational(int num, int denom):num(num),denom(denom){
  int gcdx = gcd(this->num,this->denom);
  this->num=num/gcdx;
  this->denom=denom/gcdx;
}


//------------------------------------------------------------------------------
//add & addInPlace :
Rational Rational::add(const Rational &a) const{
  return Rational(num * a.denom + a.num * denom, denom * a.denom);
}
Rational& Rational::addInPlace(const Rational &a){
  this->num = this->num*a.denom + a.num*this->denom;
  this->denom = this->denom * a.denom;
  return *this;
}


//------------------------------------------------------------------------------
//sub & subInPlace :
Rational Rational::sub(const Rational &a) const{
  return Rational(num * a.denom - a.num * denom, denom * a.denom);
}
Rational& Rational::subInPlace(const Rational &a){
  this->num = this->num*a.denom - a.num*this->denom;
  this->denom = this->denom * a.denom;
  return *this;
}


//------------------------------------------------------------------------------
//mul & mulInPlace :
Rational Rational::mul(const Rational &r) const{
  return Rational( this->num * (r.num), this->denom * (r.denom) );
}
Rational& Rational::mulInPlace(const Rational &r){
  this->num *= r.num;
  this->denom *= r.denom;
  return *this;
}
//------------------------------------------------------------------------------
//div & divInPlace :
Rational Rational::div(const Rational &r) const{
  return Rational( this->num / (r.num), this->denom / (r.denom) );
}
Rational& Rational::divInPlace(const Rational &r){
  this->num /= r.num;
  this->denom /= r.denom;
  return *this;
}
//------------------------------------------------------------------------------

//etcetera
//------------------------------------------------------------------------------
void Rational::print(std::ostream &os) const{std::cout<<this->num<<"/"<<this->denom;}
//Rational neg() const;
