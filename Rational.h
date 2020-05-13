#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
class Rational {
public:
  Rational(int num=0, int denom=1);

	Rational operator +(const Rational &right);
  Rational &addInPlace(const Rational &r);
  Rational operator -(const Rational &right);
  Rational &subInPlace(const Rational &r);
  Rational operator *(const Rational &right);
  Rational &mulInPlace(const Rational &r);
  Rational operator /(const Rational &right);
  Rational &divInPlace(const Rational &r);

  Rational neg() const;
  Rational inv() const;

  bool equals(const Rational &r) const;
  int compareTo(const Rational &r) const;

  int getNumerator() const;
  int getDenominator() const;

	void print(std::ostream &os) const;
private:
  int num, denom;
};

inline std::ostream &operator <<(std::ostream &os, const Rational &r) {r.print(os); return os;}

#endif
