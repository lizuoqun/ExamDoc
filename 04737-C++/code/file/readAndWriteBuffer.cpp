#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Student
{
public:
    char id[11];
    char name[21];
    int score;
};

int main_write()
{
    Student stu;
    // 如果要追加的话，把ios::out 改成 ios::app
    ofstream outFile("studentsByCpp.dat", ios::out | ios::binary);
    if (!outFile)
    {
        cout << "创建文件失败" << endl;
        return 0;
    }

    cout << "请输入:学号 姓名 成绩";
    while (cin >> stu.id >> stu.name >> stu.score)
        // ostream & write(char * buffer, int nCount)
        // 将内存中 buffer 所指向的 nCount 个字节的内容写入文件，返回值是对函数所作用的对象的引用。
        outFile.write((char *)&stu, sizeof(stu));

    outFile.close();
    return 0;
}

int main()
{
    Student stu;
    int count = 0, nbyte = 0;
    ifstream inFile("studentsByCpp.dat", ios::in | ios::binary);
    if (!inFile)
    {
        cout << "打开文件失败" << endl;
        return 0;
    }

    cout << "学号 姓名 成绩" << endl;
    // istream &read(char * buffer, int nCount)
    // 从文件中读取 nCount 个字节的内容，存放到 buffer 所指向的内存缓冲区中，返回值是对函数所作用的对象的引用
    while (inFile.read((char *)&stu, sizeof(stu)))
    {
        cout << left << setw(10) << stu.id << " " << setw(20) << stu.name
             << " " << setw(3) << right << stu.score << endl;
        count++;
        // int gcount();
        // 返回值就是最近一次read()函数执行时成功读取的字节数
        nbyte += inFile.gcount();
    }

    cout << "共有记录数:" << count << "字节数:" << nbyte << endl;
    inFile.close();
    return 0;
}