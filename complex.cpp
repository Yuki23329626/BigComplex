#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include "rational.h"
#include "complex.h"

using namespace std;

Complex::Complex()
    :realPart(0), imagPart(0){}

Complex::Complex(Rational realValue, Rational imagValue)
    :realPart(realValue), imagPart(imagValue){}

ostream& operator <<(ostream& outputstream, const Complex& num)
{
    if(num.imagPart.getNumerator() >= 0)
        outputstream << num.realPart << " + " << num.imagPart << "i";
    else
        outputstream << num.realPart << " - " << num.imagPart*Rational(-1) << "i";
    return outputstream;
}

const Complex operator +(const Complex& firstObj, const Complex& secondObj)
{
     return Complex(
         firstObj.realPart + secondObj.realPart,
         firstObj.imagPart + secondObj.imagPart
         );
}

const Complex operator -(const Complex& firstObj, const Complex& secondObj)
{
     return Complex(
         firstObj.realPart - secondObj.realPart,
         firstObj.imagPart - secondObj.imagPart
         );
}

const Complex operator *(const Complex& firstObj, const Complex& secondObj)
{
     return Complex(
         firstObj.realPart * secondObj.realPart - firstObj.imagPart * secondObj.imagPart,
         firstObj.realPart * secondObj.imagPart + firstObj.imagPart * secondObj.realPart
         );
}

const Complex operator /(const Complex& firstObj, const Complex& secondObj)
{
    return Complex(
        (firstObj.realPart * secondObj.realPart + firstObj.imagPart * secondObj.imagPart) / 
        (secondObj.realPart * secondObj.realPart + secondObj.imagPart * secondObj.imagPart), 
        (firstObj.imagPart * secondObj.realPart - firstObj.realPart * secondObj.imagPart) / 
        (secondObj.realPart * secondObj.realPart + secondObj.imagPart * secondObj.imagPart)
        );
}
