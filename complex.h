//This is the header file complex.h.
//This is the interface for the class Complex.
#ifndef COMPLEX_H
#define COMPLEX_H
#include "rational.h"

using namespace std;

class Complex
{
public:
    Complex();
    Complex(Rational realValue, Rational imagValue);
    friend ostream& operator <<(ostream& output, const Complex& num);
    friend const Complex operator /(const Complex& firstObj, const Complex& secondObj);
private: 
    Rational realPart;
    Rational imagPart;
};

#endif //COMPLEX_H
