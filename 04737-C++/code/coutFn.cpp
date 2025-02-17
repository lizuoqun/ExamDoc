#include <iostream>
using namespace std;

/**
 * precision()      控制保留有效数字
 * width()          控制输出宽度
 * fill()           设置填充字符
 * setf()           使用参数IFlags置位指定的标志位，返回值为置位前的标志字
 * unsetf()         清除参数IFlags指定的标志位，返回清除前的标志字
 */
int main()
{
    double values[] = {1.23, 20.3456, 300.4567, 4000.56789, 50000.1234567};
    cout.fill('*'); // 设置填充字符为星号*
    for (int i = 0; i < sizeof(values) / sizeof(double); i++)
    {
        cout << "values[" << i << "]=(";
        cout.width(10); // 设置输出宽度
        cout << values[i] << ")" << endl;
    }

    cout.fill(' '); // 设置填充字符为空格
    cout << endl;
    for (int i = 0; i < sizeof(values) / sizeof(double); i++)
    {
        cout << "values[" << i << "]=(";
        cout.width(10);        // 设置填充字符为空格
        cout.precision(i + 3); // 设置保留有效数字
        cout << values[i] << ")" << endl;
    }
}