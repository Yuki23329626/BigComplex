#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include "complex.h"

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
    BigInt a(-13), b(0);
    cout << "a > 13 ";
    if(a>13) cout<<"YES\n";
    else cout<<"NO\n";
    cout << "a < 13 ";
    if(a<13) cout<<"YES\n";
    else cout<<"NO\n";
    cout << "a == 13 ";
    if(a==13) cout<<"YES\n";
    else cout<<"NO\n";
    cout << "a >= 13 ";
    if(a>=13) cout<<"YES\n";
    else cout<<"NO\n";
    cout << "a <= 13 ";
    if(a<=13) cout<<"YES\n";
    else cout<<"NO\n";
    
    return 0;
}/**/
/*
int main(void)
{
    Rational a(13), b(-17);
    
    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;
    cout << "a.getNumerator() = " << a.getNumerator() <<endl;
    cout << "b.getDenominator() = " << b.getDenominator() <<endl<<endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "-a = " << -a << endl;
    cout << "-b = " << -b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl << endl;
    
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
    Rational aa("12", "-34"), bb("-56", "-78");
    if (aa == bb)
        cout << '1' << endl;
    else
        cout << '0' << endl;
    
    BigInt c(30);
    cout<<"30! = "<<factorial(c)<<endl;
    
    return 0;
}/**/
/*
int main()
{
    BigInt a(13);
    
    cout<<a/1<<"***\n";
    
    return 0;
}
/**/