#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << "打开文件" << endl;
    ifstream inFile;
    inFile.open("data.txt", ios::in);

    // ifstream inFile("data.txt", ios::in);

    // 关闭文件
    inFile.close();

    // 写入文件
    ofstream outFile("D:\\newfilebycpp", ios::out | ios::binary);
    return 0;
}