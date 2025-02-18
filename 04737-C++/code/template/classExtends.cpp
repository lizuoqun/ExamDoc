#include <iostream>
using namespace std;
template <class T> // 类模板
class TBase
{
    T data;

public:
    void print()
    {
        cout << data << endl;
    }
};

class Derived : public TBase<int> // 普通类Derived继承了模板类TBase<int>
{
};

int main()
{
    Derived d; // 生成派生类的对象，调用默认构造函数
    d.print(); // 调用成员函数，输出0
    return 0;
}