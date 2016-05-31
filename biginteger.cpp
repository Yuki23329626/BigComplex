#include <cstring>
#include <cstdlib>
#include <iostream>
#include "biginteger.h"
using namespace std;

int main()
{
    BigInt test;        //just testing
    cout<<test<<endl;
    test.factorial(50);
    cout<<test<<endl;
    return 0;
}

BigInt::BigInt():arraysize(10),used(0)
{
    point=new int [arraysize];
    for(int i=0; i<arraysize; i++)
        point[i]=0;
}
BigInt::BigInt(int usedVal)
{
    char temp[50];
    ltoa(usedVal,temp,10);
    int len = strlen(temp);
    used=len;
    arraysize= len +5;
    point = new int [arraysize];
    getValue(temp);
}
BigInt::BigInt(char temp[])
{
    int len = strlen(temp);

    used=len;
    arraysize= len +5;
    point = new int [arraysize];
    getValue(temp);
}
BigInt::BigInt(const BigInt& biobject)
{
    used=biobject.used;
    arraysize=biobject.arraysize;
    point = new int[arraysize];
    for(int i=0; i<biobject.used; i++)
    {
        point[i]=biobject.point[i];
    }
}
void BigInt::getValue(const char num[])
{
    int len=used;
    for(int i=0; i<used; i++)
    {
        len--;
        point[i]=num[len]-'0';
        //cout<<point[i];
    }
    //cout<<endl;
}
ostream& operator<< (ostream& outputstream,const BigInt& x)
{
    int store=0;
    for(int i=x.arraysize-1; i>=0; i--)
    {
        if(x.point[i]!=0)
        {
            store=i;
            //cout<<"store:"<<store;
            break;
        }
    }
    for(int i=store; i>=0; i--)
    {
        outputstream<<x.point[i];
        //cout<<x.point[i];
    }
    return outputstream;
}
BigInt operator + (BigInt& x,BigInt& y)
{
    int aused=x.used;
    BigInt temp(x);
    if(aused<y.used)
    {
        aused=y.used;
        temp= BigInt(y);
    }
    else

        temp.point=new int [temp.arraysize];
    for(int i=0; i<=aused; i++)
        temp.point[i]=0;
    for(int i=0; i<aused; i++)
    {
        if(i<x.used)
            temp.point[i]+=x.point[i];
        if(i<y.used)
            temp.point[i]+=y.point[i];

        if(temp.point[i]>=10&&i<x.used-1)
        {
            temp.point[i+1]=temp.point[i]/10;
            temp.point[i]%=10;
        }
        //cout<<temp.point[i];
    }
    //cout<<temp<<endl;
    return temp;
}
BigInt operator *(BigInt& x,int num)
{
    BigInt temp;

    BigInt muliper(num);
    temp.arraysize=x.arraysize+muliper.arraysize;
    temp.point = new int [temp.arraysize];
    for(int i=0; i<x.arraysize; i++)
    {
        for(int j=0; j<muliper.arraysize; j++)
        {
            temp.point[i+j]+=x.point[i]*muliper.point[j];
            if(temp.point[i+j]>=10)
            {
                temp.point[i+j+1]+=temp.point[i+j]/10;
                temp.point[i+j]%=10;

            }
            if(temp.used<i+j+1)
                    temp.used=i+j+2;
        }
    }
    //cout<<temp<<endl;
    return temp;
    temp.~BigInt();
}
BigInt::~BigInt()
{
    delete [] point;
}
bool BigInt::full()
{
    return (arraysize<=used);
}
void BigInt::larger()
{
    //cout<<"large"<<endl;
    int *newp= new int[arraysize*2];
    for(int i=0; i<used; i++)
    {
        newp[i]=point[i];
    }
    delete [] point;
    point=newp;
    arraysize*=2;
    newp=NULL;
}
void BigInt::factorial(int num)
{
    BigInt temp(1);
    //temp.point[0]=1;
    BigInt store;
    for(int i=1; i<=num; i++)
    {
        store=temp*i;
        for(int j=store.used-1;j>=0;j--)
        {
            if(store.point[j]!=0)
            {
                temp.used=j+1;
                break;
            }
        }
        if(temp.full())
               temp.larger();
        for(int j=0;j<store.used;j++)
            temp.point[j]=store.point[j];

    }
    point=temp.point;
    arraysize=temp.arraysize;
    used=temp.used;
    temp.point=NULL;
}
