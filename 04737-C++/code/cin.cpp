#include <iostream>
using namespace std;

// cin标准输入、cout标准输出
int main()
{
    // 数据类型转换
    float fa = 32.58;
    int b = static_cast<int>(fa);
    cout << b;

    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}