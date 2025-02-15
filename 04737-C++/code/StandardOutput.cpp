#include <iostream>
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
    freopen("StandardOutput.dat", "r", stdin);    // 将标准输入重定向到文件input.dat
    for (count = 0; count < 10; count++) // 从输入流中读入10个整数进行处理
    {
        // 输入流改为从文件StandardOutput.dat读取
        cin >> x;
        sum += x;
    }
    cout << "前10个整数的平均值=" << 1.0 * sum / 10 << endl;
    return 0;
}