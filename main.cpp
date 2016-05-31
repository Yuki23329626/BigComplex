#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include "complex.h"
#include "rational.h"

using namespace std;
/*
int main()
{
    Complex t1(Rational(1, 2), Rational(-3, 4));
    Complex t2(Rational(5, -6), Rational(7, 8));
    cout<<t1<<endl;

    cout << "(" << t1 << ")" << "+" << "(" << t2 << ")" << " = " << t1 + t2 << endl;
    cout << "(" << t1 << ")" << "-" << "(" << t2 << ")" << " = " << t1 - t2 << endl;
    cout << "(" << t1 << ")" << "*" << "(" << t2 << ")" << " = " << t1 * t2 << endl;
    cout << "(" << t1 << ")" << "/" << "(" << t2 << ")" << " = " << t1 / t2 << endl;

    return 0;
}
/**/
/*
int main(void)
{
    Rational input1(13,"-17"), input2(-17,"13");
    cout << "input1 = " << input1 <<endl;
    cout << "input2 = " << input2 <<endl;
    cout << "input1.getNumerator() = " << input1.getNumerator() <<endl;
    cout << "input2.getDenominator() = " << input2.getDenominator() <<endl<<endl;

    cout << "input1 + input2 = " << input1 + input2 << endl;
    cout << "input1 - input2 = " << input1 - input2 << endl;
    cout << "-input1 = " << -input1 << endl;
    cout << "-input2 = " << -input2 << endl;
    cout << "input1 * input2 = " << input1 * input2 << endl;
    cout << "input1 / input2 = " << input1 / input2 << endl << endl;
    
    BigInt a(13), b(17);
    cout<<endl<<a/b<<endl;
    
    
    return 0;
}/**/

int main(void)
{
    Complex a(Rational(12,34),Rational(56,78)), b(Rational(98,76),Rational(54,32));
    cout<<"a = "<<a<<", b = "<<b<<endl;
    
    cout<<"a + b = "<<a+b<<endl;
    cout<<"a - b = "<<a-b<<endl;
    cout<<"a * b = "<<a*b<<endl;
    cout<<"a / b = "<<a/b<<endl;
    
    return 0;
}/**/