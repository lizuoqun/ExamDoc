## 序

因为自己是做 java 技术栈的，c++也是面向对象的，复习的时候直接进行类比 java 做翻译。

这个是简短版的笔记，详细笔记可以参考：

[序章](https://www.yuque.com/unityalvin/self-study/ofglw3tq45w980tm)

## C++语言简介

### 标准输入输出

基本语法是一样的，主要区分的代码后面补充了对应 java 代码的含义

```cpp
#include <iostream> // import java.io.*;
using namespace std;

// cin标准输入、cout标准输出
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
        {
            cin >> a[i]; // System.in
        }

    for (int i = 0; i < 10; i++)
        {
            cout << a[i] << " "; // System.out.print
        }
    cout << endl; // System.out.println
}
```

### 类型转换

```cpp
#include <iostream>
using namespace std;

// 强制数据类型转换 const_cast<类型名>(表达式)
int main()
{
    // 数据类型转换
    float fa = 32.58;
    int b = static_cast<int>(fa);
    int c = (int)fa;
    int d = int(fa);
    int e = fa;
    cout << b << "    " << c << "    " << d << "    " << e << endl;
}
```

### 函数默认值

```cpp
#include <iostream>
using namespace std;

void func(int a = 1, int b = 2, int c = 3)
{
    cout << a << " " << b << " " << c << endl;
}

void exchange(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << " b=" << b << endl;
}

void quoteExchange(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << " b=" << b << endl;
}

int main()
{
    func();
    func(321);
    func(321, 654);
    func(321, 654, 987);

    int a = 100;
    int b = 200;
    cout << "数据交换前：\t\t" << "a=" << a << " b=" << b << endl;
    // 不使用引用传参原数据不会改变
    exchange(a, b);
    // quoteExchange(a, b);
    cout << "数据交换后：\t\t" << "a=" << a << " b=" << b << endl;

    return 0;
}
```

### const 与指针共同使用

```cpp
cont int *p2 = &a2;			// p2指常量
int * const p2 = &a2;		// 指针变量p2是常量
const int * const p1 = &a1;	// 数据和指针都是常量
int const * const p2 = &a2;	// 数据和指针都是常量
```

### 函数重载

一个相同的函数名多个不同参数。同名、同返回类型

```cpp
int max(int a, int b)
int max(int a, int b, int c)
int max(int a, int b, int c = 0) // 这个是错误的，会出现二义性
```

### 指针和动态内存分配

```cpp
double *p;			// 声明double类型的指针
p = new double[3];	// 分配存储空间
delete []p;			// 释放
```

### string 处理字符串

```cpp
#include <string>
string a = "hello";
bool b = 1; // 取值只有0和1

a.empty();
a.append(" world");
a.size();
a.length();
a.find("w", 0);	// 从0开始找w
a.insert(3,"w") // 从第三个位置插入w
```

### 特点

+ 以 .cpp 作为文件结尾
+ 只有一个主函数 main
    - 在主函数中执行到 return 结束
    - 执行到最后一个}结束
+ 主函数可以调用其他函数，其他函数不可调用主函数
+ 单行注释、多行注释 // 和 /***/

## 面向对象

### 结构化程序

缺点：程序在代码规模庞大时，变的难以理解、难以扩充、难以查错和难以复用

### 面向对象

面向对象程序设计的四个基本特点：抽象、封装、继承和多态。

+ 抽象 ：隐藏复杂性，提供简单的接口
+ 封装 ：将数据和方法捆绑在一起，并通过访问控制保护数据
+ 继承 ：子类继承父类的属性和方法，实现代码复用
+ 多态 ：同一个接口可以有不同的实现，允许运行时根据对象的实际类型调用相应的方法

### 类

```cpp
#include <iostream>
using namespace std;

class MyDate
{
public:
    // 构造函数
    MyDate();
    MyDate(int, int, int);
    void setDate(MyDate);
    MyDate getDate();
    void setYear(int);
    int getYear();

private:
    // 成员变量
    int year, month, day;
};

// 初始化类，有参、无参构造
MyDate::MyDate()
{
    year = 1970;
    month = 1;
    day = 1;
}

MyDate::MyDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
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

    // 对象和对象指针调用方式
    cout << md.getYear() << endl;

    cout << md1->getYear() << endl;
    return 0;
};
```

### 访问范围说明符

public：是公有的，使用它修饰的类的成员可以在程序的任何地方被访问

private：是私有的，使用它修饰的类的成员仅能在本类内被访问

protected：是保护的，介于 public 与 private 之间，使用它修饰的类的成员能在本类内及子类中被访问

### 标识符的作用域与可见性

+ 函数原型作用域：int sum();
+ 局部作用域：{}
+ 全局作用域
+ 命名空间作用域：命名空间是为了消除程序各大模块之间同名引起的歧义

## 类&对象进阶

### 构造函数

1. 构造函数的名字必须和类名相同
2. 在定义构造函数时不能指定返回类型，即：不要返回值，即使是 void 类型也不可以
3. 另外类可有多个构造函数，即函数重载；或重载
4. 构造函数的参数在排列时无顺序要求，只要保证相互对应即可
5. 构造函数可以使用默认参数
6. 在程序中声明一个对象时，程序自动调用构造函数来初始化该对象

```cpp
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
```

### 复制构造函数

```cpp
Student stud;
// 创建ss[0]中的对象时，用到了默认复制构造函数
Student ss[2] = {stud, Student()};

// 等价于下面这个
Student ss[2];
ss[0] = Student(stud);	// 调用默认复制构造函数
ss[1] = Student();	// 调用构造函数
```

### 析构函数

+ 析构函数和构造函数、复制构造函数都是构造型成员函数的基本成员；
+ 析构函数的作用是在对象消失时，释放由构造函数分配的内存；
+ 析构函数在类体里的声明形式：`~类名 ()`；
+ 析构函数的定义形式：`类名::~类名 ()  {}`；
+ 类只能定义一个析构函数，且不能指明参数；
+ 如果程序中没有定义析构函数，则编译器自动生成默认的析构函数，默认析构函数的函数体为空。
+ 使用 new 运算符动态分配了内存空间，则在析构函数中应该使用delete 释放掉这部分占用的空间。
+ 当程序先后创建几个对象时，系统按照后建先析构的原则析构对象，当使用 delete 调用析构函数时则按 delete 的顺序析构。
+ 析构函数在对象的生存期结束时被编译系统自动调用，然后对象占用的内存被回收。

```cpp
// 定义析构函数
MyDate::~MyDate()
{
    cout << "MyDate析构函数" << endl;
}

// 对象数组与 delete 语句
Student * ss = new Student[2];
delete []ss;

// 对象指针与 delete 语句
Student *ss[2] = {new Student(), new Student()};
delete ss[0];
delete ss[1];
```

### 静态变量

+ 静态全局变量：static 修饰的、在所有大括号之外声明的变量，其作用域范围是全局可见的，即在整个项目文件内都有效
+ 静态局部变量：static 修饰的、块内定义的变量，作用域从定义开始到本块结束处为止，具有全局生存期
+ 静态变量均存储在全局数据区，静态局部变量只执行一次初始化。如果未初始化则会设置为 0
+ 静态变量在退出函数后并不消失，所以下次再调用函数时，变量值已经变了。

### 类的静态成员

+ 类的静态成员有两种：静态成员变量和静态成员函数
+ 定义静态成员：在类体内定义成员时，在前面加上 static。
    - 静态成员变量不能在类体内赋值。给静态成员变量赋初值的格式如下：`类型 类名::静态成员变量=初值;`不能有 static。
    - 类体外定义成员函数时，前面也不能加 static。
+ 类的静态成员被类的所有对象共享。
+ 静态函数与静态函数之间、非静态函数与非静态函数之间是可以相互调用的，非静态成员函数内可以调用静态成员函数，但静态成员函数内不能调用非静态成员函数。

## 静态成员函数与一般成员函数的不同

+ 可以不指向某个具体的对象，只与类名连用
+ 在没有建立对象之前，静态成员就已存在
+ 静态成员是类的成员，不是对象的成员
+ 静态成员为该类的所有对象共享，它们被存储于一个公用内存中
+ 没有 this 指针，只能通过对象名或指向对象的指针访问类的数据成员
+ 静态成员函数不能被说明为虚函数
+ 静态成员函数不能直接访问非静态函数

## 静态对象与普通对象区别

+ 静态对象的构造函数在代码执行过程中，在第一次遇到它的变量定义并初始化时被调用，但直到整个程序结束之前仅调用一次；而普通对象则是遇到变量定义就被调用，遇到几次调用几次
+ 静态对象的析构函数在整个程序退出之前被调用，同样也只调用一次；而普通对象则是变量被定义几次，则析构几次。

