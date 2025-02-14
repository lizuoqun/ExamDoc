#include <iostream>
using namespace std;

class A
{
public:
    virtual void Print() // 虚函数
    {
        cout << "A::Print" << endl;
    }
};

class B : public A // 公有继承
{
public:
    virtual void Print() // 虚函数
    {
        cout << "B::Print" << endl;
    }
};

class D : public A // 公有继承
{
public:
    virtual void Print() // 虚函数
    {
        cout << "D::Print" << endl;
    }
};

class E : public B // 公有继承
{
public:
    virtual void Print() // 虚函数
    {
        cout << "E::Print" << endl;
    }
};

/**
 * 多态，使用基类引用调用哪个Print()，取决于r引用了哪个类的对象，
 * 调用时实参为基类对象，则调用函数A::Print();如果实参是派生类对象，
 * 则调用函数B::Print()。
 */
void PrintInfo(A &r) // 定义全局函数
{
    r.Print();
}

int main()
{
    A a;
    B b;
    D d;
    E e;

    // 通过基类指针实现多态
    A *pa = &a;
    B *pb = &b;
    pa->Print();
    pa = pb;
    pa->Print();
    pa = &d;
    pa->Print();
    pa = &e;
    pa->Print();

    cout << "-------------------------------------------------------" << endl;

    // 通过基类引用实现多态
    PrintInfo(a);
    PrintInfo(b);
    return 0;
}