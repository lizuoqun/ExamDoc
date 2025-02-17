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

int main_int()
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

int main_float()
{
    double x = 1234567.89, y = 1.23456789;
    cout << "无格式控制：\t\t1)x=(" << x << "), y=(" << y << ")\n";

    cout << "保留5位有效数字：\t\t2)x=(" << setprecision(5) << x << "), y=(" << y << ")\n";

    cout << "保留小数点后5位：\t\t3)x=(" << fixed << setprecision(5) << x << "), y=(" << y << ")\n";

    cout << "科学计数法且保留小数点后5位：4)x=(" << x << "), y=(" << y << "\n";

    // 显示正负号、普通小数、宽度12、不够补默认右对齐，左边补 *
    cout << "5)" << showpos << fixed << setw(12) << setfill('*') << y << endl;

    // 非负数不显示正号，宽度为12，左对齐，右边补*（如果前面没有setfill(*)，则补空格符）
    cout << "6)" << noshowpos << setw(12) << left << y << endl;

    // 宽度12，宽度不足时右对齐，左边补字符
    cout << "7)" << setw(12) << right << y << endl;

    // 宽度不足时，负号和数值分列左右，中间用填充字符填充
    cout << "8)" << setw(12) << internal << -y << endl;

    return 0;
}

// setiosflags() 设置标志字进行格式控制
int main_setiosflags()
{
    /**
     * ios::skipws      跳过输入中的空白
     * ios::left        按输出左对齐，用填充字符填充右边
     * ios::right       按输出右对齐，用填充字符填充左边
     * ios::internal    在符号位或者基数指示符后填充
     * ios::dec *       十进制表示
     * ios::oct         八进制表示
     * ios::hex         十六进制表示
     * ios::showbase    显示基数指示符
     * ios::showpoint   显示小数点
     * ios::uppercase   使用大写字母表示十六进制数
     * ios::showpos     显示正负号
     * ios:scientific   科学计数法
     * ios::fixed       定点表示浮点数
     * ios::unitbuf     输出时刷新缓冲区
     */
    double x = 12.34;
    cout << "1)" << setiosflags(ios::scientific | ios::showpos) << x << endl;
    cout << "2)" << setiosflags(ios::fixed) << x << endl;
    cout << "3)" << resetiosflags(ios::fixed) << setiosflags(ios::scientific | ios::showpos)
         << x << endl;
    cout << "4)" << resetiosflags(ios::showpos) << x << endl;
    return 0;
}