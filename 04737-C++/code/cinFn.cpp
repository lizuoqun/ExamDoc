#include <iostream>
using namespace std;
int main_get()
{
    int n = 0;
    char ch;
    while ((ch = cin.get()) != EOF)
    {
        // 当文件没有结束时继续进行循环
        // cin.get()功能类似C语言的getchar()，从键盘读入1个字符
        cout.put(ch);
        n++;
    }

    cout << "输入字符共计：" << n << endl;
    return 0;
}

int main()
{
    char buf[10];
    int i = 0;
    // 若输入流的一行超过9个字符，则会出错，循环结束
    while (cin.getline(buf, 10))
    {
        cout << ++i << ":" << buf << endl;
    }
    cout << "last:" << buf << endl;
    return 0;
}

/**
 * cin.eof()                        用于判断输入流是否已经结束。返回值为 true (1) 表示输入结束
 * cin.ignore(int n, char ch)       是跳过输入流中的 n 个字符，或跳过 ch 及其之前的所有字符
 * cin.peek()                       返回输入流中的当前字符，但是并不将该字符从输入流中取走
 */