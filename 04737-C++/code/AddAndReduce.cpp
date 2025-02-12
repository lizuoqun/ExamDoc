/**
 * @author modify
 * @description 测试++和--运算符重载
 */
#include <iostream>
using namespace std;

class AddAndReduce
{
private:
    int num;

public:
    AddAndReduce(int n) : num(n) {};
    // 在这里进行强制类型转换
    operator int() { return num; }
    AddAndReduce &operator++();
    AddAndReduce operator++(int);
    friend AddAndReduce &operator--(AddAndReduce &);
    friend AddAndReduce operator--(AddAndReduce &, int);
};

AddAndReduce &AddAndReduce::operator++()
{
    num++;
    return *this;
}

AddAndReduce AddAndReduce::operator++(int)
{
    AddAndReduce temp = *this;
    num++;
    return temp;
}

AddAndReduce &operator--(AddAndReduce &a)
{
    a.num--;
    return a;
}

AddAndReduce operator--(AddAndReduce &a, int)
{
    AddAndReduce temp = a;
    a.num--;
    return temp;
}

int main()
{
    AddAndReduce ar(5);
    cout << ar++ << endl;
    cout << "-----" << ar << endl;
    cout << ++ar << endl;
    cout << "-----" << ar << endl;
    cout << ar-- << endl;
    cout << "-----" << ar << endl;
    cout << --ar << endl;
    cout << "-----" << ar << endl;
    return 0;
}