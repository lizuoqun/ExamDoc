#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class CStudent
{
public:
	char id[11];
	char name[21];
	int score;
};

int main()
{
	CStudent stu;
	int count = 0, nbyte = 0;
	ifstream inFile("studentsByCpp.dat", ios::in | ios::binary);
	if (!inFile)
	{
		cout << "创建文件失败" << endl;
		return 0;
	}
	else
	{
		cout << "打开文件时位置指针:" << inFile.tellg() << endl;
		// id 11 + name 21 + int score 4 = 36
		cout << "每个记录大小:" << sizeof(CStudent) << endl;
	}

	cout << "学生学号姓名\t\t\t成绩\t流指针\n";
	while (inFile.read((char *)&stu, sizeof(stu)))
	{
		cout << left << setw(10) << stu.id << " " << setw(20) << stu.name
			 << " " << setw(3) << right << stu.score << endl;
		count++;
		nbyte += inFile.gcount(); // 得到本次read读取的字节数量
	}

	cout << "读取文件结束时位置指针:" << inFile.tellg() << endl;
	cout << "共有记录数:" << count << "字节数:" << nbyte << endl;
	return 0;
}