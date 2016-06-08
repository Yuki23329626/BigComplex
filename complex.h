//This is the header file complex.h.
//This is the interface for the class Complex.
#ifndef COMPLEX_H
#define COMPLEX_H
#include "rational.h"

/*
    Team: 5
    Name: 沈濃翔
    Student ID: 403410016
    Dept: 資工二
*/

using namespace std;
using namespace stdBigInt;
using namespace stdRational;

namespace stdComplex{
    
class Complex:public Rational
{
public:
    // constructor
    Complex();
    Complex(Rational realValue, Rational imagValue);
    
    Rational getRealPart();
    Rational getImagPart();
    
    // output
    friend ostream& operator <<(ostream& output, const Complex& num);
    
    // operator overloading for Arithmetic
    friend const Complex operator +(const Complex& firstObj, const Complex& secondObj);
    friend const Complex operator -(const Complex& firstObj, const Complex& secondObj);
    friend const Complex operator *(const Complex& firstObj, const Complex& secondObj);
    friend const Complex operator /(const Complex& firstObj, const Complex& secondObj);
    
    virtual ~Complex();
    
private: 
    Rational realPart;
    Rational imagPart;
};

    ostream& operator <<(ostream& output, const Complex& num);
    
    // operator overloading for Arithmetic
    const Complex operator +(const Complex& firstObj, const Complex& secondObj);
    const Complex operator -(const Complex& firstObj, const Complex& secondObj);
    const Complex operator *(const Complex& firstObj, const Complex& secondObj);
    const Complex operator /(const Complex& firstObj, const Complex& secondObj);

}

#endif //COMPLEX_H
