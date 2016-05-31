//This is the header file bigint.harderr
//This is the interface for the calss BigInt
//#ifndef BIGINT_H
//#define BIGINT_H

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// Class of BigInt
class BigInt
{
public:
    // constructor
    BigInt(const char *str);
    BigInt(int num);
    BigInt();
    BigInt(const BigInt& iniObj);

    // accessor function
    const BigInt abso() const;  // get absolute value of the bigInt object
    int getLength() const;  // get length of the bigInt object (without the sign)
    bool getSign() const;  // get the sign of the bigInt object
    const BigInt rightShift() const;

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
    
    const BigInt factorial() const;  // get the factorial n! of a non-negative bigInt n

    // destructor
    ~BigInt();
private:
    int *digit;
    int length;
    bool sign;  // sign == 0 ? posetive:negative
};

//#endif //BIGINT_H
