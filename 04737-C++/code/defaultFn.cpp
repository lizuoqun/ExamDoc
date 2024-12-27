#include <iostream>
using namespace std;

void func(int a = 1, int b = 2, int c = 3)
{
    cout << a << " " << b << " " << c << endl;
}

void exchange(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << " b=" << b << endl;
}

void quoteExchange(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << " b=" << b << endl;
}

int main()
{
    func();
    func(321);
    func(321, 654);
    func(321, 654, 987);

    int a = 100;
    int b = 200;
    cout << "数据交换前：\t\t" << "a=" << a << " b=" << b << endl;
    // 不使用引用传参原数据不会改变
    exchange(a, b);
    // quoteExchange(a, b);
    cout << "数据交换后：\t\t" << "a=" << a << " b=" << b << endl;

    return 0;
}
