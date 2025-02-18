#include <iostream>
using namespace std;

template <class T>
void exchange(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

class MyDate
{
public:
    MyDate();
    MyDate(int, int, int);
    void print();

private:
    int day, month, year;
};

MyDate::MyDate()
{
    year = 1970;
    month = 1;
    day = 1;
}

MyDate::MyDate(int d, int m, int y)
{
    year = y;
    month = m;
    day = d;
}

void MyDate::print()
{
    cout << day << "/" << month << "/" << year << endl;
}

int main()
{
    int m = 2, n = 4;
    exchange(m, n);
    cout << m << " " << n << endl;

    MyDate d1, d2(2, 3, 2001);
    d1.print();
    d2.print();
    exchange(d1, d2);
    cout << "------------exchange---------------" << endl;
    d1.print();
    d2.print();
    return 0;
}