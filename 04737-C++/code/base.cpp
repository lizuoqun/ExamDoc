#include <iostream>
using namespace std;
class Another;

// 基类
class Base
{
private:
    float x;

public:
    void print(const Another &K);
    Base(int i)
    {
        cout << "Base(" << i << ")" << endl;
    };

    ~Base()
    {
        cout << "~Base()" << endl;
    }
};

// 派生类
class Derived : public Base
{
private:
    float y;

public:
    // 构造函数，先初始化基类构造参数，再初始化自己
    Derived(int i) : Base(y)
    {
        cout << "Derived(" << i << ")" << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};

// 其他类
class Another
{
private:
    int a;

public:
    // 构造函数
    Another()
    {
        a = 100;
    }

    // 基类的成员函数声明为本类的友元
    friend void Base::print(const Another &K);
};

void Base::print(const Another &K)
{
    cout << "Base:" << K.a << endl;
}

int main()
{
    Base base(1);
    Another another;
    Derived derived(2);

    derived.print(another);

    base.print(another);
    return 0;
}

// 不写就是private
class Test : private Base
{
};

class Test2 : protected Base
{
};

// 多重继承
class Test3 : public Base, private Test, protected Test2
{
};