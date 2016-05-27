//This is the implementation file bigint.cpp of the calss BigInt.
//The interface for the calss BigInt is in the header file bigint.h.
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
#include "bigint.h"

BigInt::BigInt(const char *str)
    : digit(), length(0), sign(0)
{
    if(str[0] == '-')  //Analyzing minus sign
    {
        if(str[1] != '0')
            sign = 1;
        length = strlen(str)-1;
        digit = new int[length];
        int i;
        for(i=0 ; i<length; i++)
            digit[i] = str[i+1] - '0';
    }
    else
    {
        int i;
        length = strlen(str);
        digit = new int[length];
        for(i=0 ; i<length; i++)
            digit[i] = str[i] - '0';
    }
}

BigInt::BigInt(int num)
    : digit(), length(0), sign(0)
{
    if(num < 0)
        sign = 1,num *= -1;

    int i, temp = num;
    if(num == 0)  //if input is zero
    {
        digit = new int(0);
        length = 1;
        sign = 0;
        return;
    }
    while(temp > 0)
        temp /= 10, length++;
    digit = new int[length];

    for(i=1 ; i<=length; i++)
        digit[length-i] = num%10, num /= 10;
}

BigInt::BigInt()
    : digit(), length(1), sign(0)
{
    digit = new int(0);
}

// Copy constructor
BigInt::BigInt(const BigInt& iniObj)
    : digit(),length(iniObj.getLength()), sign(iniObj.getSign())
{
    digit = new int[length];
    int i;
    for(i = 0; i < length; i++)
        digit[i] = iniObj.digit[i];
}

// Destructor
BigInt::~BigInt()
{
    delete [] digit;
}

int BigInt::getLength() const
{
    return length;
}

bool BigInt::getSign() const
{
    return sign;
}

ostream& operator <<(ostream& outputStream, const BigInt& amount)
{
    if(amount.sign == 1)
        outputStream << "-";
    int i;
    for(i=0 ; i<amount.length ; i++)
        outputStream << amount.digit[i];

    return outputStream;
}
/*
const BigInt operator *(const BigInt& amount1, const BigInt& amount2)
{
    int sumNumerator = amount1.numerator*amount2.numerator;
    int sumDenominator = amount1.denominator*amount2.denominator;
    int sumGCD = gcd(abs(sumNumerator),sumDenominator);
    int finalNumerator = sumNumerator/sumGCD;
    int finalDenominator = sumDenominator/sumGCD;

    return BigInt(finalNumerator, finalDenominator);
}

const BigInt operator /(const BigInt& amount1, const BigInt& amount2)
{
    int sumNumerator = amount1.numerator*amount2.denominator;
    int sumDenominator = amount1.denominator*amount2.numerator;
    int sumGCD = gcd(abs(sumNumerator),sumDenominator);
    int finalNumerator = sumNumerator/sumGCD;
    int finalDenominator = sumDenominator/sumGCD;

    return BigInt(finalNumerator, finalDenominator);
}
*/

const BigInt operator +(const BigInt& amount1, const BigInt& amount2)
{
    int *sum,carry(0),i;
    if(amount1.sign == amount2.sign)
    {
        if(amount1.length >= amount2.length)
        {

            sum = new int[amount1.length+1];
            for(i = amount1.length ; i > amount1.length - amount2.length; i--)
            {
                sum[i] = amount1.digit[i-1] + amount2.digit[i-amount1.length+amount2.length-1] + carry;
                carry = sum[i]/10;
                sum[i] %= 10;
            }
            for(; i>0; i--)
            {
                sum[i] = amount1.digit[i-1] + carry;
                carry = sum[i]/10;
                sum[i]%=10;
            }
            char *str = new char[amount1.length+1];
            if(carry == 0)
            {
                for(i=0; i<amount1.length; i++)
                    str[i] = sum[i+1]+'0';
                str[i] = '\0';
            }
            else // if(carry > 0)
            {
                str[0] = carry + '0';
                for(i=1; i<=amount1.length; i++)
                    str[i] = sum[i] + '0';
                str[i] = '\0';
            }
            if(amount1.sign == 0)
                return BigInt(str);
            else
                return -BigInt(str);
        }
        else return amount2+amount1;
    }
    else return amount1 - (-amount2);
}

const BigInt operator -(const BigInt& amount1, const BigInt& amount2)
{
    int *sum,carry(0),i;
    if(amount1.sign == amount2.sign)
    {
        if(amount1.length > amount2.length)
        {
            sum = new int[amount1.length+1];
            for(i = amount1.length ; i > amount1.length - amount2.length; i--)
            {
                sum[i] = amount1.digit[i-1] - amount2.digit[i-amount1.length+amount2.length-1] - carry;
                if(sum[i]<0)
                    carry = 1, sum[i] += 10;
                else carry = 0;
            }
            for( ; i>0; i--)
            {
                sum[i] = amount1.digit[i-1] - carry;
                if(sum[i]<0)
                    carry = 1, sum[i] += 10;
                else carry = 0;
            }
            char *str = new char[amount1.length+2];
            int len(0);
            for(i=1 ; sum[i] == 0 && i < amount1.length; i++,len++);
            for(i = len ; i < amount1.length; i++)
                str[i-len] = sum[i+1] + '0';
            str[i-len] = '\0';

            if(amount1.sign == 0)
                return BigInt(str);
            else
                return -BigInt(str);
        }
        else if(amount1.length == amount2.length)
        {
            sum = new int[amount1.length+1];
            for(i = 0 ; i<amount1.length ; i++)  // if amount1 is same as amount2
                if(amount2.digit[i]!=amount1.digit[i])
                    break;
            if(i == amount1.length)
                return BigInt();

            for(i = 0 ; i<amount1.length ; i++)
                if(amount1.digit[i]>amount2.digit[i])
                {
                    for(i = amount1.length ; i>0; i--)
                    {
                        sum[i] = amount1.digit[i-1] - amount2.digit[i-1] - carry;
                        if(sum[i]<0)
                            carry = 1, sum[i] += 10;
                        else carry = 0;
                    }
                    char *str = new char[amount1.length+2];
                    int len(0);
                    for(i=1 ; sum[i] == 0 && i <= amount1.length; i++,len++);
                    for(i = len ; i < amount1.length; i++)
                        str[i-len] = sum[i+1] + '0';
                    str[i-len] = '\0';

                    if(amount1.sign == 0)
                        return BigInt(str);
                    else
                        return -BigInt(str);
                }
                else if(amount1.digit[i] < amount2.digit[i])
                    return -(amount2 - amount1);
                else
                    continue;
        }
        else
            return -(amount2 - amount1);
    }
    else
        return amount1 + (-amount2);
    return BigInt();
}

const BigInt operator -(const BigInt& amount)
{
    int i;
    char *str = new char[amount.length+2];
    if(amount.sign == 1)
    {
        for(i=0; i<amount.length; i++)
            str[i] = amount.digit[i] + '0';
    }
    else
    {
        str[0] = '-';
        for(i=1; i<=amount.length; i++)
            str[i] = amount.digit[i-1] + '0';
    }
    str[i] = '\0';
    return BigInt(str);
}

BigInt& BigInt::operator =(const BigInt& rightObj)
{
    if(length != rightObj.length)
    {
        delete [] digit;
        digit = new int[rightObj.length];
    }
    length = rightObj.length;
    sign = rightObj.sign;
    int i;
    for(i = 0; i < rightObj.length; i++)
        digit[i] = rightObj.digit[i];

    return *this;
}
