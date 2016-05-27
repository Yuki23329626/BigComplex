#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include "rational.h"

/*
    Name: 沈濃翔
    Student ID: 403410016
    Dept: 資工二
*/
using namespace std;

void Rational::normalize() //normalize the input data
{
    if(denominator < 0)
        numerator *= -1, denominator *= -1;
    int sumGCD = gcd(abs(numerator),denominator);
    numerator = numerator/sumGCD;
    denominator = denominator/sumGCD;
}

Rational::Rational(int numeratorValue, int denominatorValue)
    : numerator(numeratorValue),denominator(denominatorValue)
{
    normalize();
}

Rational::Rational(int numeratorValue)
    : numerator(numeratorValue),denominator(1)
{
    normalize();
}

Rational::Rational()
    : numerator(0),denominator(1)
{}

int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const
{
    return denominator;
}

ostream& operator <<(ostream& outputStream, const Rational& amount)
{
    int absNumerator = abs(amount.numerator);
    int absDenominator = abs(amount.denominator);
    if(amount.numerator < 0 || amount.denominator < 0)
        outputStream << "-";
    outputStream << absNumerator;

    if(absDenominator > 1){
    outputStream << '/';
    outputStream << absDenominator;
    }
    return outputStream;
}

istream& operator >>(istream& inputStream, Rational& amount)
{
    string inputData;
    inputStream >> inputData;
    int i;
    for(i=0, amount.numerator = 0; inputData[i] != '/' && inputData[i] != '\0'; i++)
        amount.numerator = amount.numerator*10 + inputData[i] - '0';
    if(inputData[i] == '\0')
    {
        return inputStream;
    }
    i++;
    for(amount.denominator = 0; inputData[i] != '\0'; i++)
        amount.denominator = amount.denominator*10 + inputData[i] - '0';
    if(amount.denominator <= 0)
    {
        cout << "Illegal input \n";
        exit(1);
    }
    return inputStream;
}

int gcd( int a, int b )
{
    int temp;
    while ( a != 0 )
    {
        temp = a;
        a = b%a;
        b = temp;
    }
    return b;
}

const Rational operator +(const Rational& amount1, const Rational& amount2)
{
    int sumNumerator = amount1.getNumerator()*amount2.getDenominator()+
                       amount2.getNumerator()*amount1.getDenominator();
    int sumDenominator = amount1.getDenominator()*amount2.getDenominator();
    int sumGCD = gcd(abs(sumNumerator),sumDenominator);
    int finalNumerator = sumNumerator/sumGCD;
    int finalDenominator = sumDenominator/sumGCD;

    return Rational(finalNumerator, finalDenominator);
}

const Rational operator -(const Rational& amount1, const Rational& amount2)
{
    int sumNumerator = amount1.getNumerator()*amount2.getDenominator()-
                       amount2.getNumerator()*amount1.getDenominator();
    int sumDenominator = amount1.getDenominator()*amount2.getDenominator();
    int sumGCD = gcd(abs(sumNumerator),sumDenominator);
    int finalNumerator = sumNumerator/sumGCD;
    int finalDenominator = sumDenominator/sumGCD;

    return Rational(finalNumerator, finalDenominator);
}

const Rational operator -(const Rational& amount)
{
    return Rational(-amount.getNumerator(), amount.getDenominator());
}

const Rational operator *(const Rational& amount1, const Rational& amount2)
{
    int sumNumerator = amount1.numerator*amount2.numerator;
    int sumDenominator = amount1.denominator*amount2.denominator;
    int sumGCD = gcd(abs(sumNumerator),sumDenominator);
    int finalNumerator = sumNumerator/sumGCD;
    int finalDenominator = sumDenominator/sumGCD;

    return Rational(finalNumerator, finalDenominator);
}

const Rational operator /(const Rational& amount1, const Rational& amount2)
{
    int sumNumerator = amount1.numerator*amount2.denominator;
    int sumDenominator = amount1.denominator*amount2.numerator;
    int sumGCD = gcd(abs(sumNumerator),sumDenominator);
    int finalNumerator = sumNumerator/sumGCD;
    int finalDenominator = sumDenominator/sumGCD;

    return Rational(finalNumerator, finalDenominator);
}

bool operator ==(const Rational& amount1, const Rational& amount2)
{
    return (amount1.getNumerator()*amount2.getDenominator() ==
            amount2.getNumerator()*amount1.getDenominator());
}

bool Rational::operator <(const Rational& amount2) const
{
    return (numerator*amount2.getDenominator() < amount2.getNumerator()*denominator);
}

bool Rational::operator <=(const Rational& amount2) const
{
    return (numerator*amount2.getDenominator() <= amount2.getNumerator()*denominator);
}

bool Rational::operator >(const Rational& amount2) const
{
    return (numerator*amount2.getDenominator() > amount2.getNumerator()*denominator);
}

bool Rational::operator >=(const Rational& amount2) const
{
    return (numerator*amount2.getDenominator() >= amount2.getNumerator()*denominator);
}

int& Rational::operator [](int index)
{
    if(index == 0)
        return numerator;
    else if(index == 1)
        return denominator;
    else
    {
        cout << "Illegal index \n";
        exit(1);
    }
}
