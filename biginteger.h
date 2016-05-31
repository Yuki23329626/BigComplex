//This is the header file of biginteger.cpp
//This is the interface for the calss BigInt
#ifndef BIGINTEGER_H_INCLUDED
#define BIGINTEGER_H_INCLUDED
#include <iostream>

using namespace std;
class BigInt
{
//except the overloading <<
//all the function deal the biginteger in
//small     to  big
//point[0]  to  point[used]

public:
    BigInt();
    BigInt(char temp[]);
    BigInt(int arrSizeVal);
    BigInt(const BigInt& biobject);
    
    void getValue(const char num[]);
    bool full();
    void larger();//arraysize*2
    void factorial(int num);//1*......*num
    
    friend ostream& operator<<(ostream& outputstream,const BigInt& x);
    //read back the dynamic array 
    //big-------->small
    friend BigInt operator +(BigInt& x,BigInt& y);
    friend BigInt operator *(BigInt& x,int muliper);
    
    ~BigInt();
private:
    int *point;
    int arraysize;
    int used;
};



#endif // BIGINTEGER_H_INCLUDED
