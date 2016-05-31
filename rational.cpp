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
        numerator = numerator * -1, denominator = denominator * -1;
    BigInt sumGCD = gcd(numerator.abso(),denominator);
    numerator = numerator/sumGCD;
    denominator = denominator/sumGCD;
}


Rational::Rational(BigInt numeratorValue, BigInt denominatorValue)
    : numerator(numeratorValue),denominator(denominatorValue)
{
    normalize();
}

Rational::Rational(BigInt numeratorValue)
    : numerator(numeratorValue),denominator(1)
{
    normalize();
}

Rational::Rational()
    : numerator(0),denominator(1)
{}


BigInt Rational::getNumerator() const
{
    return numerator;
}

BigInt Rational::getDenominator() const
{
    return denominator;
}


ostream& operator <<(ostream& outputStream, const Rational& amount)
{
    BigInt absNumerator = amount.numerator.abso();
    BigInt absDenominator = amount.denominator.abso();

    if(amount.numerator < 0 || amount.denominator < 0)
        outputStream << "-";
    outputStream << absNumerator;

    if(absDenominator > 1){
    outputStream << '/';
    outputStream << absDenominator;
    }
    return outputStream;
}

/*
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
*/

const BigInt gcd(const BigInt amount1, const BigInt amount2 )
{
    BigInt temp, lValue(amount1.abso()), rValue(amount2.abso());
    while (!(lValue == 0))
    {
        temp = lValue;
        lValue = rValue % lValue;
        rValue = temp;
    }

    if(amount1.getSign() != amount2.getSign())
        return -BigInt(rValue);
    else
        return BigInt(rValue);
}

const Rational operator +(const Rational& amount1, const Rational& amount2)
{
    BigInt sumNumerator = amount1.getNumerator()*amount2.getDenominator()+
                       amount2.getNumerator()*amount1.getDenominator();
    BigInt sumDenominator = amount1.getDenominator()*amount2.getDenominator();
    BigInt sumGCD = gcd(sumNumerator.abso(),sumDenominator);
    BigInt finalNumerator = sumNumerator/sumGCD;
    BigInt finalDenominator = sumDenominator/sumGCD;

    return Rational(finalNumerator, finalDenominator);
}

const Rational operator -(const Rational& amount1, const Rational& amount2)
{
    BigInt sumNumerator = amount1.getNumerator()*amount2.getDenominator()-
                       amount2.getNumerator()*amount1.getDenominator();
    BigInt sumDenominator = amount1.getDenominator()*amount2.getDenominator();
    BigInt sumGCD = gcd(sumNumerator.abso(),sumDenominator);
    BigInt finalNumerator = sumNumerator/sumGCD;
    BigInt finalDenominator = sumDenominator/sumGCD;

    return Rational(finalNumerator, finalDenominator);
}

const Rational operator -(const Rational& amount)
{
    return Rational(-amount.getNumerator(), amount.getDenominator());
}

const Rational operator *(const Rational& amount1, const Rational& amount2)
{
    BigInt sumNumerator = amount1.numerator*amount2.numerator;
    BigInt sumDenominator = amount1.denominator*amount2.denominator;
    BigInt sumGCD = gcd(sumNumerator.abso(),sumDenominator);
    BigInt finalNumerator = sumNumerator/sumGCD;
    BigInt finalDenominator = sumDenominator/sumGCD;

    return Rational(finalNumerator, finalDenominator);
}

const Rational operator /(const Rational& amount1, const Rational& amount2)
{
    if(amount2 == Rational(0))
    {
        cout<<"Divisor cannot be zero.\n";
        exit(1);
    }
    BigInt sumNumerator = amount1.numerator*amount2.denominator;
    BigInt sumDenominator = amount1.denominator*amount2.numerator;
    BigInt sumGCD = gcd(sumNumerator.abso(),sumDenominator);
    BigInt finalNumerator = sumNumerator/sumGCD;
    BigInt finalDenominator = sumDenominator/sumGCD;

    return Rational(finalNumerator, finalDenominator);
}

bool operator ==(const Rational& amount1, const Rational& amount2)
{
    return (amount1.getNumerator() == amount2.getNumerator() &&
            amount1.getDenominator() == amount2.getDenominator());
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

BigInt& Rational::operator [](int index)
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
/**/