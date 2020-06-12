#include "rational.h"
#include "gcd.h"
#include "rational_exception.h"

//------------------------------------------------------------------------------
//constructor: (just ONE constructor -- uses default parameters)
Rational::Rational(int num, int denom) : num(num), denom(denom)
{
  if (denom == 0)
  {
    RationalException r("RationalException: can't instantiate Rational with denom 0");
    throw r;
  }
  int gcdx = gcd(this->num, this->denom);
  this->num = num / gcdx;
  this->denom = denom / gcdx;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//getters:
int Rational::getNumerator() const { return num; }
int Rational::getDenominator() const { return denom; }
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//add & addInPlace:
Rational operator+(const Rational &r1, const Rational &r2)
{
  return Rational(r1.getNumerator() * r2.getDenominator() +
                      r2.getNumerator() * r1.getDenominator(),
                  r1.getDenominator() * r2.getDenominator());
}

Rational &Rational::operator+=(const Rational &a)
{
  int newNum = this->num * a.denom + a.num * this->denom;
  int newDenom = this->denom * a.denom;
  this->num = newNum / gcd(newNum, newDenom);
  this->denom = newDenom / gcd(newNum, newDenom);
  return *this;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//sub & subInPlace:
Rational operator-(const Rational &r1, const Rational &r2)
{
  return Rational(r1.getNumerator() * r2.getDenominator() -
                      r2.getNumerator() * r1.getDenominator(),
                  r1.getDenominator() * r2.getDenominator());
}
Rational &Rational::operator-=(const Rational &a)
{
  int newNum = this->num * a.denom - a.num * this->denom;
  int newDenom = this->denom * a.denom;
  this->num = newNum / gcd(newNum, newDenom);
  this->denom = newDenom / gcd(newNum, newDenom);
  return *this;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//mul & mulInPlace:
Rational operator*(const Rational &r1, const Rational &r2)
{
  return Rational(r1.getNumerator() * (r2.getNumerator()),
                  r1.getDenominator() * (r2.getDenominator()));
}
Rational &Rational::operator*=(const Rational &r)
{
  this->num *= r.num;
  this->denom *= r.denom;
  return *this;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//div & divInPlace:
Rational operator/(const Rational &r1, const Rational &r2)
{
  return Rational(r1.getNumerator() * (r2.getDenominator()),
                  r1.getDenominator() * (r2.getNumerator()));
}
Rational &Rational::operator/=(const Rational &r)
{
  this->num *= r.denom;
  this->denom *= r.num;
  return *this;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//else:
Rational Rational::operator-() const
{
  Rational r(-1 * this->getNumerator(), this->getDenominator());
  return r;
}

Rational Rational::inv() const
{
  if (num == 0)
  {
    RationalException r("RationalException: can't instantiate Rational with denom 0");
    throw r;
  }
  int newNum = denom;
  int newDenom = num;
  Rational r(newNum, newDenom);
  return r;
}

bool operator==(const Rational &r1, const Rational &r2)
{
  double x = (float)(r1.getNumerator()) / (float)(r1.getDenominator());
  double y = (float)(r2.getNumerator()) / (float)(r2.getDenominator());
  return (x == y) ? true : false;
}

int Rational::compareTo(const Rational &r) const
{
  double x = (float)(this->num) / (float)(this->denom);
  double y = (float)(r.num) / (float)(r.denom);
  if (x > y)
    return 1;
  if (x < y)
    return -1;
  if (x == y)
    return 0;
}
//------------------------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, const Rational &r)
{
  r.print(os);
  return os;
}

void Rational::print(std::ostream &os) const
{
  if (getDenominator() != 1)
    os << getNumerator() << "/" << getDenominator();
  else
    os << getNumerator();
}