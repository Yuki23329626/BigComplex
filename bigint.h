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
    int getLength() const;
    bool getSign() const;

    // operator overloading
    friend ostream& operator <<(ostream& outputStream, const BigInt& amount);
    friend const BigInt operator +(const BigInt& amount1, const BigInt& amount2);
    friend const BigInt operator -(const BigInt& amount1, const BigInt& amount2);
    friend const BigInt operator -(const BigInt& amount);
    BigInt& operator =(const BigInt& rightValue);

    // destructor
    ~BigInt();
private:
    int *digit;
    int length;
    bool sign;
};

//#endif //BIGINT_H
