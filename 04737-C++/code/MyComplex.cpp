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

    // 友元，插入，os是out别名
    friend ostream &operator<<(ostream &os, const MyComplex &c);

    // 友元，提取，is是cin是别名
    friend istream &operator>>(istream &is, MyComplex &c);
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

ostream &operator<<(ostream &os, const MyComplex &c)
{
    if (c.imag >= 0)
        os << c.real << "+" << c.imag << "i"; // 以 a+bi 的形式输出
    else
        os << c.real << "-" << (-c.imag) << "i"; // 以 a-bi 的形式输出
    return os;
}

istream &operator>>(istream &is, MyComplex &c)
{
    string s;
    is >> s; // 将a+bi作为字符串读入，a+bi中间不能有空格

    // 查找虚部
    int pos = s.find("+", 0);
    if (pos == -1)
        // 虚部为负数时
        pos = s.find("-", 1);

    // 从0到+或-符号之间的字符取出，即分离出代表实部的字符串
    string sReal = s.substr(0, pos);

    // c_str()函数返回一个指向字符串的指针
    // atof()能将参数内容转换成浮点数
    c.real = atof(sReal.c_str());

    sReal = s.substr(pos, s.length() - pos - 1); // 分离出代表虚部的字符串
    c.imag = atof(sReal.c_str());
    return is;
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