#include <iostream>
using namespace std;

class MyDate
{
public:
    // 构造函数
    MyDate();
    MyDate(int, int, int);
    void setDate(MyDate);
    MyDate getDate();
    void setYear(int);
    int getYear();

private:
    // 成员变量
    int year, month, day;
};

// 初始化类，有参、无参构造
MyDate::MyDate()
{
    year = 1970;
    month = 1;
    day = 1;
}

MyDate::MyDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

void MyDate::setDate(MyDate d)
{
    year = d.year;
    month = d.month;
    day = d.day;
}

int MyDate::getYear()
{
    return year;
}

int main()
{
    MyDate md;

    MyDate *md1 = new MyDate(2001, 1, 2);

    // 对象和对象指针调用方式
    cout << md.getYear() << endl;

    cout << md1->getYear() << endl;
    return 0;
};