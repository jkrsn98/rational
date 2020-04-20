#ifndef GCD_H
#define GCD_H

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

#endif
