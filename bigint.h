//This is the header file bigint.harderr
//This is the interface for the calss BigInt
#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
    Team: 5
    Name: 蔡幸均
    Student ID: 403410025
    Dept: 資工二
*/

namespace stdBigInt{
// Class of BigInt
class BigInt
{
public:
    // constructor
    BigInt(const char *str);
    BigInt(int num);
    BigInt(int* num, int tmpLength, bool tmpSign);
    BigInt();
    BigInt(const BigInt& iniObj);

    // accessor function
    const BigInt abso() const;  // get absolute value of the bigInt object
    int getLength() const;  // get length of the bigInt object (without the sign)
    bool getSign() const;  // get the sign of the bigInt object
    const BigInt rightShift() const;
    const BigInt leftShift(int times) const;

    const BigInt factorial();
    friend const BigInt factorial(BigInt bigNum);  // get the factorial n! of a non-negative bigInt n

    // operator overloading
    friend ostream& operator <<(ostream& outputStream, const BigInt& amount);
    friend const BigInt operator +(const BigInt& amount1, const BigInt& amount2);
    friend const BigInt operator -(const BigInt& amount1, const BigInt& amount2);
    friend const BigInt operator *(const BigInt& amount1, const BigInt& amount2);
    friend const BigInt operator /(const BigInt& amount1, const BigInt& amount2);
    friend const BigInt operator %(const BigInt& amount1, const BigInt& amount2);
    friend const BigInt operator -(const BigInt& amount);  // negation
    friend bool operator ==(const BigInt& amount1, const BigInt& amount2);
    friend bool operator >(const BigInt& amount1, const BigInt& amount2);
    friend bool operator <(const BigInt& amount1, const BigInt& amount2);
    friend bool operator >=(const BigInt& amount1, const BigInt& amount2);
    friend bool operator <=(const BigInt& amount1, const BigInt& amount2);

    BigInt& operator =(const BigInt& rightValue);

    // destructor
    virtual ~BigInt();
private:
    int *digit;
    int length;
    bool sign;  // sign == 0 ? posetive:negative
};

    const BigInt factorial(BigInt bigNum);  // get the factorial n! of a non-negative bigInt n

    ostream& operator <<(ostream& outputStream, const BigInt& amount);
    const BigInt operator +(const BigInt& amount1, const BigInt& amount2);
    const BigInt operator -(const BigInt& amount1, const BigInt& amount2);
    const BigInt operator *(const BigInt& amount1, const BigInt& amount2);
    const BigInt operator /(const BigInt& amount1, const BigInt& amount2);
    const BigInt operator %(const BigInt& amount1, const BigInt& amount2);
    const BigInt operator -(const BigInt& amount);  // negation
    bool operator ==(const BigInt& amount1, const BigInt& amount2);
    bool operator >(const BigInt& amount1, const BigInt& amount2);
    bool operator <(const BigInt& amount1, const BigInt& amount2);
    bool operator >=(const BigInt& amount1, const BigInt& amount2);
    bool operator <=(const BigInt& amount1, const BigInt& amount2);

}

#endif //BIGINT_H
