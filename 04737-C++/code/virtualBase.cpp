#include <iostream>
using namespace std;

class A
{
public:
    int a;
    void showa()
    {
        cout << "a=" << a << endl;
    }
};

class B : virtual public A
{
public:
    int b;
};

class C : virtual public A
{
public:
    int c;
};

class D : public B, public C
{
public:
    int d;
};

int main()
{
    D Dobj;
    Dobj.a = 11;
    Dobj.b = 22;

    // 输出a=11，若不是虚继承，此行会出错！因为“Dobj.showa()”具有二义性
    Dobj.showa();
    cout << "Dobj.b=" << Dobj.b << endl; // 输出 Dobi.b = 22
}
