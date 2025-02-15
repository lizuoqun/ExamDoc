#include <iostream>
#include <iomanip>
using namespace std;

int main_out()
{
    int x, y;
    y = 10;
    // D:\soft\C\mingw64\bin
    freopen("StandardOutput.txt", "w", stdout);
    if (y == 0)
    {
        cerr << "Division by zero!";
    }
    else
    {
        // 上面通过freopen重定向了，cout会写入到StandardOutput.txt
        cout << "------------------" << x / y << endl;
    }
    return 0;
}

int main_in()
{
    int x, count, sum = 0;
    freopen("StandardOutput.dat", "r", stdin);
    for (count = 0; count < 10; count++)
    {
        // 输入流改为从文件StandardOutput.dat读取
        cin >> x;
        // 是否读取到文件的最后
        // cin.eof();
        sum += x;
    }
    cout << "前10个整数的平均值=" << 1.0 * sum / 10 << endl;
    return 0;
}

int main()
{
    int n = 65535, m = 20;
    // 1)分别输出一个整数的十进制、十六进制和八进制表示
    cout << "1)" << n << "=" << hex << n << "=" << oct << n << endl;

    // 2)使用setbase分别输出一个整数的十进制、十六进制和八进制表示
    cout << "2)" << setbase(10) << m << "=" << setbase(16) << m << "=" << setbase(8) << m << endl;

    cout << "3)" << showbase; // 输出表示数值进制的前缀
    cout << setbase(10) << m << "=" << setbase(16) << m << "=" << setbase(8) << m << endl;
    return 0;
}