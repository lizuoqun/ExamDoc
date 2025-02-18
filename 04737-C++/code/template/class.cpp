#include <iostream>
using namespace std;

template <class T1, class T2>
class Pair
{
public:
    T1 first;
    T2 second;
    Pair(T1 k, T2 v) : first(k), second(v) {}
    bool operator<(const Pair<T1, T2> &p) const;
};

template <class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p) const
{
    // 仅比较第一个成员变量的大小
    return first < p.first;
}

int main()
{

    Pair<string, int> stu1("zhangsan", 18);
    Pair<string, int> stu2("lisi", 19);

    Pair<int, int> coordinate(10, 20);
    Pair<string, string> dic("word", "单词");

    cout << "stu1\t" << stu1.first << "\t" << stu1.second << endl;
    cout << "stu2\t" << stu2.first << "\t" << stu2.second << endl;
    cout << "coord\t" << coordinate.first << "\t" << coordinate.second << endl;
    cout << "dic\t" << dic.first << "\t" << dic.second << endl;
    cout << "-------------------------------------" << endl;

    bool a = stu1 < stu2;
    cout << a << endl;

    return 0;
}