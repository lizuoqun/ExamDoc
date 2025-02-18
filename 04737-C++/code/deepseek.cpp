#include <iostream>
#include <thread>
using namespace std;
/**
 * @author: modify
 * 疑似DeepSeek源码泄露
 */
int main()
{
    string question;
    cout << "给DeepSeek发送消息" << endl;
    cin >> question;

    cout << "正在搜索中";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "服务器繁忙" << endl;
    return 0;
}