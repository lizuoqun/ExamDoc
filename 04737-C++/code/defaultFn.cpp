#include <iostream>
using namespace std;

void func(int a = 1, int b = 2, int c = 3)
{
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    func();
    func(321);
    func(321, 654);
    func(321, 654, 987);

    return 0;
}
