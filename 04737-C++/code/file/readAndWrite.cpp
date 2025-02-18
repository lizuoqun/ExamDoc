#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main_write()
{
    char id[11], name[21];
    int score;
    ofstream outFile;
    outFile.open("scoreByCpp.txt", ios::out);
    if (!outFile)
    {
        cout << "创建文件失败" << endl;
        return 0;
    }

    cout << "请输入学号姓名成绩" << endl;

    while (cin >> id >> name >> score)
        outFile << id << " " << name << " " << score << endl;

    outFile.close();

    return 0;
}

int main_read()
{

    char id[11], name[21];
    int score;

    ifstream inFile;

    inFile.open("scoreByCpp.txt", ios::in);

    if (!inFile)
    {
        cout << "打开文件失败" << endl;
        return 0;
    }

    cout << "学号\t\t姓名\t\t成绩\n";

    while (inFile >> id >> name >> score)
        cout << left << setw(15) << id << " " << setw(15) << name << " " << setw(3) << right << score << endl;

    inFile.close();
    return 0;
}