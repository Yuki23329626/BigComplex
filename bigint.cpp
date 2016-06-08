//This is the implementation file bigint.cpp of the calss BigInt.
//The interface for the calss BigInt is in the header file bigint.h.
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "bigint.h"

/*
    Team: 5
    Name: 蔡幸均
    Student ID: 403410025
    Dept: 資工二
*/

using namespace std;

namespace stdBigInt{

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

BigInt::BigInt(int* num, int tmpLength, bool tmpSign)
    : digit(), length(), sign()
{
    sign = tmpSign;

    int i;
    if(num[0] > 0)
    {
        length = tmpLength;
        digit = new int[length];
        for(i = 0; i < tmpLength; i++)
            digit[i] = num[i];
    }
    else
    {
        length = tmpLength-1;
        digit = new int[length];
        for(i = 1; i < tmpLength; i++)
            digit[i-1] = num[i];
    }
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
    //cout<<"~BigInt"<<endl;
    delete [] digit;
}

const BigInt factorial(BigInt bigNum)
{
    if(bigNum > 0){
        BigInt sum(1);
        int i;
        for( i = 2 ;i <= bigNum; i++)
            sum = sum * i;
        return sum;
    }
    else
        return BigInt(1);
}

const BigInt BigInt::abso() const
{
    return BigInt(digit, length, 0);
}

const BigInt BigInt::factorial()
{
    if(*this > 0){
        BigInt sum(1);
        int i;
        for( i = 2 ;i <= *this; i++)
            sum = sum * i;
        return sum;
    }
    else
        return BigInt(1);
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
    int *digit = amount.digit;
    if(amount.sign == 1)
        outputStream << "-";
    int i;
    for(i=0 ; i<amount.length ; i++)
        outputStream << digit[i];//<<" ";

    return outputStream;
}

bool operator ==(const BigInt& amount1, const BigInt& amount2)
{
    int *digit1 = amount1.digit, *digit2 = amount2.digit;
    if(amount1.length != amount2.length || amount1.sign != amount2.sign)
        return 0;
    else
    {
        int i;
        for(i = 0; i<amount1.length; i++)
            if(digit1[i] != digit2[i])
                return 0;
        return 1;
    }
}

bool operator >(const BigInt& amount1, const BigInt& amount2)
{
    int *digit1 = amount1.digit, *digit2 = amount2.digit;
    if(amount1 == amount2 || amount1.sign > amount2.sign)
        return 0;
    else if(amount1.sign < amount2.sign)
        return 1;
    else if(amount1.sign == 0)
    {
        if(amount1.length > amount2.length)
            return 1;
        else if(amount1.length < amount2.length)
            return 0;
        else
        {
            int i;
            for(i = 0; i<amount1.length; i++){
                if(digit1[i] == digit2[i])
                    continue;
                if(digit1[i] > digit2[i])
                    return 1;
                else
                    break;
            }
            return 0;
        }
    }
    else
    {
        if(amount1.length < amount2.length)
            return 1;
        else if(amount1.length > amount2.length)
            return 0;
        else
        {
            int i;
            for(i = 0; i<amount1.length; i++){
                if(digit1[i] == digit2[i])
                    continue;
                if(digit1[i] < digit2[i])
                    return 1;
                else
                    break;
            }
            return 0;
        }
    }
}

bool operator <(const BigInt& amount1, const BigInt& amount2)
{
    return (amount2 > amount1);
}

bool operator >=(const BigInt& amount1, const BigInt& amount2)
{
    return ((amount1 > amount2) || (amount1 == amount2));
}

bool operator <=(const BigInt& amount1, const BigInt& amount2)
{
    return ((amount2 > amount1) || (amount1 == amount2));
}

const BigInt operator *(const BigInt& amount1, const BigInt& amount2)
{
    if(amount1==0 || amount2==0) return BigInt();
    int i,j,carry;
    int *sum = new int[amount1.length + amount2.length];
    int *digit1 = amount1.digit, *digit2 = amount2.digit;

    for(i = 0 ;i < amount1.length+amount2.length; i++) // initialize
        sum[i] = 0;

    for(i = amount1.length-1; i >= 0; i--)
    {
        carry = 0;
        for(j = amount2.length-1; j >= 0; j--){
            sum[i+j+1] += carry + digit1[i]*digit2[j];
            carry = sum[i+j+1] / 10;
            sum[i+j+1] %= 10;
        }
        sum[i+j+1] += carry;
    }
    if(amount1.sign == amount2.sign)
        return BigInt(sum, amount1.length + amount2.length, 0);
    else
        return BigInt(sum, amount1.length + amount2.length, 1);
}

const BigInt BigInt::rightShift() const // this /= 10
{
    return BigInt(digit, length-1, sign);
}

const BigInt BigInt::leftShift(int times) const // this *= 10^times
{
    int i, *arr = new int[length + times];

    for(i = 0 ; i < length ; i++)
        arr[i] = digit[i];
    for(; i < length+times ; i++)
        arr[i] = 0;

    return BigInt(arr, length + times, sign);
}

const BigInt operator /(const BigInt& amount1, const BigInt& amount2)
{
    // magn = magnificent;
    BigInt quotient, magn(amount2), dividend(amount1), divisor(amount2);
    dividend.sign = divisor.sign = 0;
    if(dividend < divisor)
        return BigInt(0);

    if(dividend > divisor)
        magn = magn.leftShift(dividend.length - divisor.length);

    //if(dividend < magn)
    //    magn = magn.rightShift(); // magn = magn/10;

    if(dividend >= magn)
        quotient.length = amount1.length - amount2.length + 1;
    else{
        quotient.length = amount1.length - amount2.length;
        magn = magn.rightShift(); // magn = magn/10;
    }

    quotient.digit = new int[quotient.length];
    for(int i = 0 ; i < quotient.length ; i++)
        quotient.digit[i] = 0;

    int index(0);
    while(dividend >= divisor){
        while(dividend >= magn)
        {
            quotient.digit[index]++;
            dividend = dividend - magn;
        }
        magn = magn.rightShift();
        index++;
    }

    if(amount1.getSign() == amount2.getSign())
        return BigInt( quotient.digit , quotient.length, quotient.sign);
    else
        return BigInt( quotient.digit , quotient.length, !quotient.sign);
}

const BigInt operator %(const BigInt& amount1, const BigInt& amount2)
{
    if(amount1 < amount2)
        return amount1;
    return amount1 - amount2*(amount1/amount2);
}

const BigInt operator +(const BigInt& amount1, const BigInt& amount2)
{
    int *sum,carry(0),i;
    int *digit1 = amount1.digit, *digit2 = amount2.digit;
    if(amount1.sign == amount2.sign)
    {
        if(amount1.length >= amount2.length)
        {

            sum = new int[amount1.length+1];
            for(i = amount1.length ; i > amount1.length - amount2.length; i--)
            {
                sum[i] = digit1[i-1] + digit2[i-amount1.length+amount2.length-1] + carry;
                carry = sum[i]/10;
                sum[i] %= 10;
            }
            for(; i>0; i--)
            {
                sum[i] = digit1[i-1] + carry;
                carry = sum[i] / 10;
                sum[i] %= 10;
            }
            sum[0] = carry;

            return BigInt(sum, amount1.length+1, amount1.sign);
        }
        else return amount2 + amount1;
    }
    else return amount1 - (-amount2);
}

const BigInt operator -(const BigInt& amount1, const BigInt& amount2)
{
    int *sum,carry(0),i;
    int *digit1 = amount1.digit, *digit2 = amount2.digit;
    if(amount1.sign == amount2.sign)
    {
        if(amount1.length > amount2.length)
        {
            sum = new int[amount1.length+1];
            for(i = amount1.length ; i > amount1.length - amount2.length; i--)
            {
                sum[i] = digit1[i-1] - digit2[i-amount1.length+amount2.length-1] - carry;
                if(sum[i]<0)
                    carry = 1, sum[i] += 10;
                else carry = 0;
            }
            for( ; i>0; i--)
            {
                sum[i] = digit1[i-1] - carry;
                if(sum[i]<0)
                    carry = 1, sum[i] += 10;
                else carry = 0;
            }

            int len(0);
            for(i=1 ; sum[i] == 0 && i < amount1.length; i++,len++);

            return BigInt(&sum[len+1], amount1.length - len, amount1.sign);
        }
        else if(amount1.length == amount2.length)
        {
            sum = new int[amount1.length+1];
            for(i = 0 ; i<amount1.length ; i++)  // if amount1 is same as amount2
                if(digit2[i]!=digit1[i])
                    break;
            if(i == amount1.length)
                return BigInt();

            for(i = 0 ; i<amount1.length ; i++)
                if(digit1[i]>digit2[i])
                {
                    for(i = amount1.length ; i>0; i--)
                    {
                        sum[i] = digit1[i-1] - digit2[i-1] - carry;
                        if(sum[i]<0)
                            carry = 1, sum[i] += 10;
                        else carry = 0;
                    }

                    int len(0);
                    for(i=1 ; sum[i] == 0 && i < amount1.length; i++,len++);

                    return BigInt(&sum[len+1], amount1.length - len, amount1.sign);
                }
                else if(digit1[i] < digit2[i])
                    return -(amount2 - amount1);
                else
                    continue;
        }
        else{
            return -(amount2 - amount1);
        }
    }
    else
        return amount1 + (-amount2);
    return BigInt();
}

const BigInt operator -(const BigInt& amount)
{
    return BigInt(amount.digit, amount.length, !amount.sign);
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
}
