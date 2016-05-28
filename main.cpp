#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include "complex.h"
#include "rational.h"

using namespace std;
/**/
int main()
{
    Complex t1(Rational(1, 2), Rational(-3, 4));
    Complex t2(Rational(5, -6), Rational(7, 8));
    
    cout << "(" << t1 << ")" << "+" << "(" << t2 << ")" << " = " << t1 + t2 << endl;
    cout << "(" << t1 << ")" << "-" << "(" << t2 << ")" << " = " << t1 - t2 << endl;
    cout << "(" << t1 << ")" << "*" << "(" << t2 << ")" << " = " << t1 * t2 << endl;
    cout << "(" << t1 << ")" << "/" << "(" << t2 << ")" << " = " << t1 / t2 << endl;
    
    return 0;
}
/*

int main(void)
{
    Rational input1(13,17), input2(17,13);

    cout << "input1 = " << input1 << endl;
    input1.normalize();
    cout << "After normalize, input1 = " << input1 << endl;
    cout << "input2 = " << input2 << endl;
    input2.normalize();
    cout << "After normalize, input2 = " << input2 << "\n\n";

    cout << "input1 + input2 = " << input1 + input2 << endl;
    cout << "input1 - input2 = " << input1 - input2 << endl;
    cout << "-input1 = " << -input1 << endl;
    cout << "-input2 = " << -input2 << endl;
    cout << "input1 * input2 = " << input1 * input2 << endl;
    cout << "input1 / input2 = " << input1 / input2 << endl << endl;

    if(input1 == input2)
        cout << "input1 == input2  YES\n";
    else
        cout << "input1 == input2  NO\n";
    if(input1 < input2)
        cout << "input1 <  input2  YES\n";
    else
        cout << "input1 <  input2  NO\n";
    if(input1 <= input2)
        cout << "input1 <= input2  YES\n";
    else
        cout << "input1 <= input2  NO\n";
    if(input1 > input2)
        cout << "input1 >  input2  YES\n";
    else
        cout << "input1 >  input2  NO\n";
    if(input1 >= input2)
        cout << "input1 >= input2  YES\n";
    else
        cout << "input1 >= input2  NO\n\n";

    cout << "input1[0] = " << input1[0] << endl;
    cout << "input1[1] = " << input1[1] << endl;
    cout << "input2[0] = " << input2[0] << endl;
    cout << "input2[1] = " << input2[1] << endl<<endl<<endl;

    
    BigInt a("314159265358979323846264338327950288419716939937510"), c(a);
    BigInt *b = new BigInt(1123581321);

    c = a + *b;
    cout << a << " + " << *b << " = " << c << endl;
    c = a - *b;
    cout << a << " - " << *b << " = " << c << endl << endl;

    BigInt d("-987654321987654321"), e(-987654321);

    a = d - e;
    cout << d << " - " << e << " = " << a <<endl;

    *b = e - -111111111;
    cout << e << " - " << -111111111 << " = " << *b <<endl;

    c = d + "123456789123456789";
    cout << d << " + " << "123456789123456789" << " = " << c <<endl;

    cout <<  a << " + " << *b << " = " <<  a + *b <<endl;
    cout <<  a << " + " <<  c << " = " <<  a +  c <<endl;
    cout <<  a << " + " <<  d << " = " <<  a +  d <<endl;
    cout <<  a << " - " <<  e << " = " <<  a -  e <<endl;
    cout << *b << " - " <<  c << " = " << *b -  c <<endl;
    cout << *b << " - " <<  d << " = " << *b -  d <<endl;
    cout << *b << " - " <<  e << " = " << *b -  e <<endl;
    cout <<  c << " - " <<  d << " = " <<  c -  d <<endl;
    cout <<  c << " - " <<  e << " = " <<  c -  e <<endl;
    cout <<  d << " - " <<  e << " = " <<  d -  e <<endl<<endl;

    BigInt aa, bb, cc, dd;
    aa =  97, bb = -97, cc = "197", dd = "-107";
    cout << aa << " + " << bb.abso() << " = " << aa + bb.abso() << endl;
    cout << aa << " + " << cc << " = " << aa + cc << endl;
    cout << aa << " + " << dd << " = " << aa + dd << endl;
    cout << bb << " + " << cc << " = " << bb + cc << endl;
    cout << bb << " + " << dd << " = " << bb + dd << endl;
    cout << cc << " + " << dd << " = " << cc + dd << endl;
    cout << aa << " - " << bb << " = " << aa - bb << endl;
    cout << aa << " - " << cc << " = " << aa - cc << endl;
    cout << aa << " - " << dd << " = " << aa - dd << endl;
    cout << bb << " - " << cc << " = " << bb - cc << endl;
    cout << bb << " - " << dd << " = " << bb - dd << endl;
    cout << cc << " - " << dd << " = " << cc - dd << endl;
    
    BigInt ff = 9876, ee = -54;
    cout << ee << " * " << ff << " = " << ee * ff << endl;
}/**/
