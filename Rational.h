#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
class Rational {
public:
  Rational();
  Rational(int num);
  Rational(int num, int denom);

	Rational add(const Rational &r) const; //const states the receiver does not change
	Rational &addInPlace(const Rational &r);
  Rational sub(const Rational &r) const;
  Rational &subInPlace(const Rational &r);
  Rational mul(const Rational &r) const;
  Rational &mulInPlace(const Rational &r);
  Rational div(const Rational &r) const;
  Rational &divInPlace(const Rational &r);


  Rational neg() const;

  int getNum(){return num;}
  int getDenom(){return denom;}
  Rational getRational(){
    Rational r(num,denom);
    return r;
  }

	void print(std::ostream &os) const;
private:
  int num, denom;
};

inline std::ostream &operator <<(std::ostream &os, const Rational &r) {r.print(os); return os;}

#endif
