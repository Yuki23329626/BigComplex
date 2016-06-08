#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include "complex.h"

/*
    Team: 5
    Name: 沈濃翔
    Student ID: 403410016
    Dept: 資工二
*/

using namespace std;
using namespace stdRational;
using namespace stdBigInt;
using namespace stdComplex;

int main(void)
{
    BigInt a(100), b(520), c(128), d(320);
    Complex c1(Rational(1,7), Rational(-8,15)), c2(Rational(a.factorial(),b.factorial()), Rational(c.factorial(),d.factorial()));

    cout<<"c1 = "<<c1<<"\n"<<"c2 = "<<c2<<endl;

    cout<<"c1 / c2 = "<< c1/c2 <<endl;

    return 0;
}
