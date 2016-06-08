//This is the header file rational.h.
//This is the interface for the class Rational.
#ifndef RATIONAL_H
#define RATIONAL_H
#include "bigint.h"

using namespace std;
using namespace stdBigInt;

/*
    Team: 5
    Name: 張光緯
    Student ID: 403410017
    Dept: 資工二
*/

namespace stdRational{
class Rational:public BigInt
{
public:
    // constructor
    Rational(BigInt numeratorValue, BigInt denominatorValue);
    Rational(BigInt numeratorValue);
    Rational();

    // accessor function
    BigInt getNumerator() const;
    BigInt getDenominator() const;
    const bool getSign() const;
    
    // operator overloading

    friend ostream& operator <<(ostream& outputStream, const Rational& amount);
    friend const Rational operator *(const Rational& amount1, const Rational& amount2);
    friend const Rational operator /(const Rational& amount1, const Rational& amount2);
    friend bool operator ==(const Rational& amount1, const Rational& amount2);
    bool operator <(const Rational& amount2) const;
    bool operator <=(const Rational& amount2) const;
    bool operator >(const Rational& amount2) const;
    bool operator >=(const Rational& amount2) const;
    BigInt& operator [](int index);
    // index must be positive integer

    void normalize();
    // turn the fraction into the simplest fraction
    
    virtual ~Rational();

private:
    BigInt numerator;
    BigInt denominator;
};

const BigInt gcd(const BigInt amount1, const BigInt amount2 );
// input must be positive integer

const Rational operator +(const Rational& amount1, const Rational& amount2);
// addition
const Rational operator -(const Rational& amount1, const Rational& amount2);
// subtraction
const Rational operator -(const Rational& amount);
// negation

    ostream& operator <<(ostream& outputStream, const Rational& amount);
    const Rational operator *(const Rational& amount1, const Rational& amount2);
    const Rational operator /(const Rational& amount1, const Rational& amount2);
    bool operator ==(const Rational& amount1, const Rational& amount2);

}

#endif //RATIONAL_H
