#include <iostream>
using namespace std;

// 强制数据类型转换 const_cast<类型名>(表达式)
int main()
{
    // 数据类型转换
    float fa = 32.58;
    int b = static_cast<int>(fa);
    int c = (int)fa;
    int d = int(fa);
    int e = fa;
    cout << b << "    " << c << "    " << d << "    " << e << endl;
}