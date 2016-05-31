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

const BigInt BigInt::factorial() const
{
    if(*this > 0){
        BigInt sum(1), i(1);
        for( ;i <= *this; i = i+1)
            sum = sum * i, cout<<i<<"*\n";
        return sum;
    }
    else 
        return BigInt(0);
}

const BigInt BigInt::abso() const
{
    if(sign == 0)
        return *this;
    return - *this;
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

bool operator ==(const BigInt& amount1, const BigInt& amount2)
{
    if(amount1.length != amount2.length || amount1.sign != amount2.sign)
        return 0;
    else
    {
        int i;
        for(i = 0; i<amount1.length; i++)
            if(amount1.digit[i] != amount2.digit[i])
                return 0;
        return 1;
    }
}

bool operator >(const BigInt& amount1, const BigInt& amount2)
{
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
                if(amount1.digit[i] == amount2.digit[i])
                    continue;
                if(amount1.digit[i] > amount2.digit[i])
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
                if(amount1.digit[i] == amount2.digit[i])
                    continue;
                if(amount1.digit[i] < amount2.digit[i])
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

const BigInt operator !(const BigInt& amount)
{
    BigInt sum(1);
    BigInt i;
    for(i = 1; i <= amount; i = i+1)
    {
        sum = sum * i;
    }
    return sum;
}

const BigInt operator *(const BigInt& amount1, const BigInt& amount2)
{
    int i,j,k;
    int *temp = new int[amount1.length + amount2.length];
    int *sum = new int[amount1.length + amount2.length];
    
    for(i = 0 ;i < amount1.length+amount2.length; i++) // initialize
        temp[i] = sum[i] = 0;

    for(i = amount1.length-1; i >= 0; i--)
    {
        for(j = amount2.length-1; j >= 0; j--)
            temp[i+j+1] = amount1.digit[i]*amount2.digit[j];
            
        int carry(0);
        for(k = amount1.length+amount2.length-1 ; k >= 0 ;k--)
        {
            sum[k] = sum[k] + temp[k] + carry;
            temp[k] = 0;
            carry = sum[k] / 10;
            sum[k] %= 10;
        }
    }
    
    char *str = new char[amount1.length+1];
    if(sum[0] > 0){
        for(i = 0; i < amount1.length+amount2.length; i++)
            str[i] = sum[i] + '0';
        str[i] = '\0';
    }
    else{
        for(i = 1; i < amount1.length+amount2.length; i++)
            str[i-1] = sum[i] + '0';
        str[i-1] = '\0';
    }
    
    if(amount1.sign == amount2.sign)
        return BigInt(str);
    else
        return -BigInt(str);
}

const BigInt BigInt::rightShift() const
{
    int i;
    char *str = new char[this->length+1];
    for(i = 0; i < this->length - 1; i++)
        str[i] = this->digit[i] + '0';
    str[i] = '\0';
    return BigInt(str);
}

const BigInt operator /(const BigInt& amount1, const BigInt& amount2)
{
    // magn = magnificent;
    BigInt count(0), magn(1), lValue(amount1.abso()), rValue(amount2.abso());
    
    if(lValue < rValue)
        return BigInt(0);
    
    while(lValue >= rValue*magn)
        magn = magn*10;
    magn = magn.rightShift(); // magn = magn/10;
    
    while(lValue >= rValue){
        while(lValue >= rValue*magn)
        {
            count = count + magn;
            lValue = lValue - rValue*magn;
        }
        magn = magn.rightShift();
    }
    
    if(amount1.getSign() != amount2.getSign())
        return -count;
    else
        return count;
}

const BigInt operator %(const BigInt& amount1, const BigInt& amount2)
{
    return amount1 - amount2*(amount1/amount2);
}

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
