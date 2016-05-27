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
    outputstream << num.realPart << " + " << num.imagPart << "i\n";
    return outputstream;
}

const Complex operator /(const Complex& firstObj, const Complex& secondObj)
{
    return Complex((firstObj.realPart * secondObj.realPart + firstObj.imagPart * secondObj.imagPart) / 
                    (secondObj.realPart * secondObj.realPart + secondObj.imagPart * secondObj.imagPart), 
                    (firstObj.imagPart * secondObj.realPart - firstObj.realPart * secondObj.imagPart) / 
                    (secondObj.realPart * secondObj.realPart + secondObj.imagPart * secondObj.imagPart)
                    );
}
