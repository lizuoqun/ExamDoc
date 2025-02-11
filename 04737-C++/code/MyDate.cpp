#include <iostream>
using namespace std;

class MyDate
{
public:
    // 构造函数
    MyDate();
    MyDate(int, int, int);
    // 复制构造函数
    MyDate(const MyDate &);
    // 静态函数
    static int getCount();
    // 常量函数
    int getCount2() const;
    void setDate(MyDate);
    MyDate getDate();
    void setYear(int);
    int getYear();

private:
    // 成员变量
    int year, month, day;
    static int count;
};

// 初始化静态变量
int MyDate::count = 0;

int MyDate::getCount()
{
    // 这里面不能访问非静态变量
    return count;
}

int MyDate::getCount2() const
{
    cout << count << endl;
}

// 初始化类，有参、无参构造
MyDate::MyDate()
{
    year = 1970;
    month = 1;
    day = 1;
}

// 无参构造，和上面相等
// MyDate::MyDate():year(1970),month(1),day(1){}

MyDate::MyDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

// 有参构造改写
// MyDate::MyDate(int y, int m, int d):year(y),month(m),day(d){};

// 实现复制构造函数
MyDate::MyDate(const MyDate &d)
{
    cout << "复制构造函数" << d.year << endl;
}

// 定义析构函数
MyDate::~MyDate()
{
    cout << "MyDate析构函数" << endl;
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

    // 定义常量对象
    const MyDate md2(2002, 2, 3);
    MyDate const md3(2003, 3, 4);

    // 对象和对象指针调用方式
    cout << md.getYear() << endl;

    cout << md1->getYear() << endl;
    return 0;
};