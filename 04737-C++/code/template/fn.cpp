#include <iostream>
using namespace std;

// 函数模版
template <typename T>
T abs(T x)
{
    return x < 0 ? -x : x;
}

int main()
{
    cout << abs(-10) << endl;
    cout << abs(10.5) << endl;
    return 0;
}