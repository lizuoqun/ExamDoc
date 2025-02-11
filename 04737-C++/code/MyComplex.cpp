/**
 * @author: modify
 * @description: 运算符重载
 */
#include <iostream>
using namespace std;

// 复数类
class MyComplex
{
private:
    double real, imag; // 复数的实部，虚部
public:
    MyComplex();                   // 构造函数
    MyComplex(double r, double i); // 构造函数
    void print();                  // 成员函数

    // 运算符重载 加法、减法重载
    MyComplex operator-(const MyComplex &c);

    // 声明友元函数
    friend MyComplex operator+(const MyComplex &cl, const MyComplex &c2);

    // 重载赋值运算符
    MyComplex &operator=(const MyComplex &c);
    MyComplex &operator=(double);
};

MyComplex::MyComplex()
{
    real = 0;
    imag = 0;
}

MyComplex::MyComplex(double r, double i)
{
    real = r;
    imag = i;
}

void MyComplex::print()
{
    cout << "(" << real << "," << imag << ")" << endl;
}

// 符号重载 重载成员函数和重载友元函数的区别
MyComplex MyComplex::operator-(const MyComplex &c)
{
    return MyComplex(this->real - c.real, this->imag - c.imag);
};

MyComplex operator+(const MyComplex &cl, const MyComplex &c2)
{
    return MyComplex(cl.real + c2.real, cl.imag + c2.imag);
}

MyComplex &MyComplex::operator=(const MyComplex &c)
{
    real = c.real;
    imag = c.imag;
    return *this;
}

MyComplex &MyComplex::operator=(double d)
{
    real = d;
    imag = 0;
    return *this;
}

int main()
{
    MyComplex c1(1, 2), c2(3, 4);
    MyComplex c3 = c1 - c2;
    c3.print();
    MyComplex c4 = c1 + c2;
    c4.print();
    return 0;
}