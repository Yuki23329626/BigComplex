#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include "rational.h"
#include "complex.h"

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

Complex::Complex()
    :realPart(0), imagPart(0){}

Complex::Complex(Rational realValue, Rational imagValue)
    :realPart(realValue), imagPart(imagValue){}

Complex::~Complex()
{
    //cout<<"~Complex"<<endl;
}

Rational Complex::getRealPart()
{
    return realPart;
}

Rational Complex::getImagPart()
{
    return imagPart;
}

ostream& operator <<(ostream& outputstream, const Complex& num)
{
    if(num.imagPart.getNumerator() >= 0){
        if(!(num.realPart.getNumerator() == 0))
            outputstream << num.realPart << " + ";
        if(!(num.imagPart.getNumerator() == 0))
            outputstream << num.imagPart << "i";
        if( (num.realPart.getNumerator() == 0) && (num.imagPart.getNumerator() == 0) )
            outputstream << "0";
    }
    else{
        if(!(num.realPart.getNumerator() == 0))
            outputstream << num.realPart << " - ";
        if(!(num.imagPart.getNumerator() == 0))
            outputstream << -num.imagPart << "i";
        if( (num.realPart.getNumerator() == 0) && (num.imagPart.getNumerator() == 0) )
            outputstream << "0";
    }
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

}
