//This is the header file rational.h.
//This is the interface for the class Rational.
#ifndef RATIONAL_H
#define RATIONAL_H
#include "bigint.h"

using namespace std;

//Class for rational number
class Rational:public BigInt
{
public:
    // constructor
    Rational(int numeratorValue, int denominatorValue);
    Rational(int numeratorValue);
    Rational();

    // accessor function
    int getNumerator() const;
    int getDenominator() const;

    // operator overloading
    friend ostream& operator <<(ostream& outputStream, const Rational& amount);
    friend istream& operator >>(istream& inputStream, Rational& amount);
    friend const Rational operator *(const Rational& amount1, const Rational& amount2);
    friend const Rational operator /(const Rational& amount1, const Rational& amount2);
    friend bool operator ==(const Rational& amount1, const Rational& amount2);
    bool operator <(const Rational& amount2) const;
    bool operator <=(const Rational& amount2) const;
    bool operator >(const Rational& amount2) const;
    bool operator >=(const Rational& amount2) const;
    int& operator [](int index);
    // index must be positive integer

    void normalize();
    // turn the fraction into the most simple fraction
private:
    int numerator;
    int denominator;
};

int gcd( int a, int b );
// input must be positive integer

const Rational operator +(const Rational& amount1, const Rational& amount2);
const Rational operator -(const Rational& amount1, const Rational& amount2);
const Rational operator -(const Rational& amount);

#endif //RATIONAL_H
