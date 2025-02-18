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

###  const 与指针共同使用
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

### 静态成员函数与一般成员函数的不同
+ 可以不指向某个具体的对象，只与类名连用
+ 在没有建立对象之前，静态成员就已存在
+ 静态成员是类的成员，不是对象的成员
+ 静态成员为该类的所有对象共享，它们被存储于一个公用内存中
+ 没有 this 指针，只能通过对象名或指向对象的指针访问类的数据成员
+ 静态成员函数不能被说明为虚函数
+ 静态成员函数不能直接访问非静态函数

### 静态对象与普通对象区别
+ 静态对象的构造函数在代码执行过程中，在第一次遇到它的变量定义并初始化时被调用，但直到整个程序结束之前仅调用一次；而普通对象则是遇到变量定义就被调用，遇到几次调用几次
+ 静态对象的析构函数在整个程序退出之前被调用，同样也只调用一次；而普通对象则是变量被定义几次，则析构几次。

### 成员对象和封闭类
+ 类 Student 和类 MyDate 类 Student 中的成员变量 birthday 是类 MyDate 的对象，birthday 就是成员对象，Student 是封闭类
+ 执行封闭类的构造函数时，先执行成员对象的构造函数，然后再执行本类的构造函数
+ 封闭类对象生成时，先执行所有成员对象的构造函数。然后执行封闭类自己的构造函数
+ 成员对象构造函数的执行次序与成员对象在类定义中的说明次序一致，与其他次序无关
+ 当封闭类对象消亡时，先执行封闭类的析构函数，然后再执行成员对象的析构函数，成员对象析构函数的执行次序和构造函数的执行次序相反，即先构造的后析构

### 友元
+ 为了兼顾 C 设计的习惯与 C++ 信息隐藏的特点，而特意增加的功能。
+ 友元机制是对一些类外的函数打开的一个特殊通道，授权它们能够访问本类的私有成员变量。
+ 友元的概念破坏了类的封装性和信息隐藏，但有助于数据共享，能够提高程序执行的效率。
+ 友元机制包括友元函数和友元类。

#### 友元函数
定义类时，可以把函数（包括全局函数和其他类的成员函数）声明为友元

```cpp
    // 友元函数，全局和类友元函数
    friend void getRandom();
    friend void MyDate::setDate(MyDate);
```

#### 友元类
+ 将一个类 B 说明为另一个类 A 的友元类，则类 B 中的所有函数都是类 A 的友元函数。
+ 友元类的关系是单向的、不可传递的

### this 指针
用 this->标识，和 java 的 this 是一样的，

```cpp
MyDate::MyDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
    this->year = y;
}
```

## 运算符重载
### 概念
给已有的运算符赋予多重含义，使同一个运算符作用于不同类型的数据时产生不同的行为

目的是使得 C++ 中的运算符也能够用来操作对象

实质是编写以运算符为名称的函数，使用运算符的表达式就被解释为对重载函数的调用

不可重载的运算符

```cpp
成员访问运算符		.
成员指针访问运算符	.*	->*
域运算符				::
长度运算符			sizeof
条件运算符			?:
预处理符号			#
```

### 重载运算符为类的成员函数&友元函数
```cpp
#include <iostream>
using namespace std;

// 复数类
class MyComplex
{
private:
    double real, imag; // 复数的实部，虚部
public:
    MyComplex();                   // 构造函数
    MyComplex(double r, double i); // 构造函数
    void print();                  // 成员函数

    // 运算符重载 加法、减法重载
    MyComplex operator-(const MyComplex &c);

    // 声明友元函数
    friend MyComplex operator+(const MyComplex &cl, const MyComplex &c2);
};

MyComplex::MyComplex()
{
    real = 0;
    imag = 0;
}

MyComplex::MyComplex(double r, double i)
{
    real = r;
    imag = i;
}

void MyComplex::print()
{
    cout << "(" << real << "," << imag << ")" << endl;
}

// 符号重载 重载成员函数和重载友元函数的区别
MyComplex MyComplex::operator-(const MyComplex &c)
{
    return MyComplex(this->real - c.real, this->imag - c.imag);
};

MyComplex operator+(const MyComplex &cl, const MyComplex &c2)
{
    return MyComplex(cl.real + c2.real, cl.imag + c2.imag);
}

int main()
{
    MyComplex c1(1, 2), c2(3, 4);
    MyComplex c3 = c1 - c2;
    c3.print();
    MyComplex c4 = c1 + c2;
    c4.print();
    return 0;
}
```

### 重载赋值运算符
### 浅拷贝&深拷贝
+ 浅拷贝：同类对象之间可以通过赋值运算符“=”互相赋值。如果没有经过重载
+ 如果赋值的对象中涉及指针或是引用，则它们之间是互相关联的，一个值变化了，另一个值也跟着变化。因为对象中的指针指向的是同一个内存地址

### 重载流插入运算符和流提取运算符
```cpp
// 友元，插入，os是out别名
friend ostream &operator<<(ostream &os, const MyComplex &c);

// 友元，提取，is是cin是别名
friend istream &operator>>(istream &is, MyComplex &c);


ostream &operator<<(ostream &os, const MyComplex &c)
{
    if (c.imag >= 0)
        os << c.real << "+" << c.imag << "i"; // 以 a+bi 的形式输出
    else
        os << c.real << "-" << (-c.imag) << "i"; // 以 a-bi 的形式输出
    return os;
}

istream &operator>>(istream &is, MyComplex &c)
{
    string s;
    is >> s; // 将a+bi作为字符串读入，a+bi中间不能有空格

    // 查找虚部
    int pos = s.find("+", 0);
    if (pos == -1)
        // 虚部为负数时
        pos = s.find("-", 1);

    // 从0到+或-符号之间的字符取出，即分离出代表实部的字符串
    string sReal = s.substr(0, pos);

    // c_str()函数返回一个指向字符串的指针
    // atof()能将参数内容转换成浮点数
    c.real = atof(sReal.c_str());

    sReal = s.substr(pos, s.length() - pos - 1); // 分离出代表虚部的字符串
    c.imag = atof(sReal.c_str());
    return is;
}
```

### 重载自增自减运算符
```cpp
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
```

## 继承&派生
### 概念
类的继承&派生编程语言都是一样的概念，这里省略

### protected 访问范围说明符
+ 派生类可以直接访问基类中的保护成员
+ 派生类不能直接访问基类中成员变量是私有成员
+ 将基类部分成员设置为保护成员，既能起到隐藏的目的，又避免了派生类成员函数要访问它们时只能间接访问所带来的麻烦
+ 派生类的成员函数只能访问所作用的那个对象（即 this 指针指向的对象）的基类保护成员，不能访问其他基类对象的基类保护成员

### 多重继承
一个派生类可以同时有多个基类

```cpp
class A : public B, public C, public D{}
```

二义性：多重继承时，如果多个基类中有重名的成员。添加`基类::`作为前缀，指明需要访问从继承于基类

### 访问控制
+ 公有 public 继承：派生类都可以访问
+ 私有 private 继承：第一级派生类可以访问基类的公有、保护成员，调用公有函数访问私有成员
+ 保护 protected 继承：公有成员和保护成员都以保护成员的身份出现在派生类中

### 派生的构造和析构
子类不继承父类的构造

```cpp
#include <iostream>
using namespace std;
class Another;

// 基类
class Base
{
private:
    float x;

public:
    void print(const Another &K);
    Base(int i)
    {
        cout << "Base(" << i << ")" << endl;
    };

    ~Base()
    {
        cout << "~Base()" << endl;
    }
};

// 派生类
class Derived : public Base
{
private:
    float y;

public:
    // 构造函数，先初始化基类构造参数，再初始化自己
    Derived(int i) : Base(y)
    {
        cout << "Derived(" << i << ")" << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};

// 其他类
class Another
{
private:
    int a;

public:
    // 构造函数
    Another()
    {
        a = 100;
    }

    // 基类的成员函数声明为本类的友元
    friend void Base::print(const Another &K);
};

void Base::print(const Another &K)
{
    cout << "Base:" << K.a << endl;
}

int main()
{
    Base base(1);
    Another another;
    Derived derived(2);

    derived.print(another);

    base.print(another);
    return 0;
}

// 不写就是private
class Test : private Base
{
};

class Test2 : protected Base
{
};

// 多重继承
class Test3 : public Base, private Test, protected Test2
{
};
```

输出结果：

```bash
Base(1)
Base(0)
Derived(2)
Base:100
Base:100
~Derived()
~Base()
~Base()
```

### 类之间的关系
+ 继承关系：B 继承于 A，那么在使用A 的地方都可以用 B 代替，但在用 B 对象时不能用 A 对象代替。is a
+ 组合关系：一个类以另一个类的对象作为成员变量（封闭类）has a

### 多层次派生
一个类只能被一次说明为某个派生类的直接基类，可以多次的成为间接基类

### 基类派生类间指针转换
+ 子类对象可以赋值给父类对象
+ 子类对象可以初始化父类引用
+ 子类指针可以赋值给父类指针
+ 父类指针不可直接赋值给子类指针，需要进行强转
+ 父类指针指向子类对象，也不能通过父类指针访问父类中不存在而子类中存在的成员函数
+ 父类指针，不管是指向父类对象还是子类对象都只能调用父类的函数
+ 子类指针调用的是子类的函数，子类没有则调用父类的同名函数

## 多态和虚函数
### 多态
不同对象可以调用相同名称的函数，出现完全不同的行为的现象（接口复用）。分为编译时多态和运行时多态

+ 编译：编译阶段就能绑定调用语句与调用函数入口地址（函数重载）
+ 运行：函数调用与代码入口地址的绑定需要在运行时刻才能确定（动态联编或动态绑定）

### 虚函数
```cpp
#include <iostream>
using namespace std;

class A
{
public:
    virtual void Print() // 虚函数
    {
        cout << "A::Print" << endl;
    }
};

class B : public A // 公有继承
{
public:
    virtual void Print() // 虚函数
    {
        cout << "B::Print" << endl;
    }
};

class D : public A // 公有继承
{
public:
    virtual void Print() // 虚函数
    {
        cout << "D::Print" << endl;
    }
};

class E : public B // 公有继承
{
public:
    virtual void Print() // 虚函数
    {
        cout << "E::Print" << endl;
    }
};

/**
 * 多态，使用基类引用调用哪个Print()，取决于r引用了哪个类的对象，
 * 调用时实参为基类对象，则调用函数A::Print();如果实参是派生类对象，
 * 则调用函数B::Print()。
 */
void PrintInfo(A &r) // 定义全局函数
{
    r.Print();
}

int main()
{
    A a;
    B b;
    D d;
    E e;

    // 通过基类指针实现多态
    A *pa = &a;
    B *pb = &b;
    pa->Print();
    pa = pb;
    pa->Print();
    pa = &d;
    pa->Print();
    pa = &e;
    pa->Print();

    cout << "-------------------------------------------------------" << endl;

    // 通过基类引用实现多态
    PrintInfo(a);
    PrintInfo(b);
    return 0;
}
```

### 多态的使用
+ 通过基类的指针、引用可以调用虚函数实现多态
+ 通过普通成员函数（静态成员函数、构造函数和析构函数除外）中调用其他虚成员函数，并且是多态的。
+ 可以在构造函数和析构函数中调用虚函数。但这样调用的虚函数不是多态的。

### 虚析构函数
+ 不支持虚构造函数，但支持虚析构函数。
+ 虚析构函数没有参数，没有返回值类型，声明虚析构函数的一般格式：`virtual ~类名();`
+ 基类的析构函数被说明为虚函数，则派生类的析构函数，无论是否使用 virtual 说明，都自动成为虚函数
+ 使用虚析构函数的目的是为了在对象消亡时实现多态具体来说，设置了虚析构函数后，在使用指针或引用时可以动态绑定，实现运行时的多态，保证使用基类类型的指针能够调用适当的析构函数针对不同的对象进行清理工作，以避免造成内存泄漏。

### 纯虚函数
纯虚函数的一般形式为：`virtual 函数类型函数名(参数列表) = 0`；

### 抽象类
+ 一个类可说明多个纯虚函数，包含纯虚函数的类称为抽象类
+ 抽象类的派生类中，如果没有给出全部纯虚函数的定义，则派生类继续是抽象类
+ 抽象类只能作为基类来派生新类，不能创建抽象类的对象，即抽象类不能实例化一个对象
+ 可以定义抽象类的指针和引用。这样的指针和引用可以指向并访问派生类的成员，这种访问具有多态性
+ 抽象类至少含有一个虚函数，而且至少有一个虚函数是纯虚函数

### 虚基类
```cpp
#include <iostream>
using namespace std;

class A
{
public:
    int a;
    void showa()
    {
        cout << "a=" << a << endl;
    }
};

class B : virtual public A
{
public:
    int b;
};

class C : virtual public A
{
public:
    int c;
};

class D : public B, public C
{
public:
    int d;
};

int main()
{
    D Dobj;
    Dobj.a = 11;
    Dobj.b = 22;

    // 输出a=11，若不是虚继承，此行会出错！因为“Dobj.showa()”具有二义性
    Dobj.showa();
    cout << "Dobj.b=" << Dobj.b << endl; // 输出 Dobi.b = 22
}

```

## 输入输出流
### 流类对象
![](https://cdn.nlark.com/yuque/0/2025/png/42913202/1739518811477-510a02d6-3ffd-43b1-aee9-89cde9d97167.png)

```plain
graph TB
A[ios] ---> B(istream)
A ---> C(ostream)
B---->F[fstream]
B--->D(iostream)
C--->D(iostream)
D --> E[ifstream]
C---->G(ofstream)
```

| 类名 | 类名 | 描述 | 包含文件 |
| --- | --- | --- | --- |
| 抽象流基类 | ios | 基类 | ios |
| 输入流类 | istream | 通用输入流基类和其他输入流基类，cin 是该类的对象 | istream |
| | ifstream | 文件输入流类，用于从文件中读取数据 | fstream |
| 输出流类 | ostream | 通用输出流基类和其他输出流基类，cout 是该类的对象 | ostream |
| | ofstream | 文件输出流类，用于向文件写入数据 | fstream |
| 输入输出流类 | iostream | 通用输入输出流基类和其他输入输出流基类 | iostream |
| | fstream | 文件输入输出流类，既能从文件中读取数据，也能向文件中写入数据 | fstream |


### 标准流对象
iostream 中定义了 4 个标准流对象：

+ cin（标准输入流）：用于从键盘输入数据，是流类 istream 的对象
+ cout（标准输出流）：用于向屏幕输出数据，是流类 ostream 的对象，可以重定向输出到文件
+ cerr（非缓冲错误输出流）：cerr 不使用缓冲区，直接向显示器输出信，不能重定向。
+ clog（缓冲错误输出流）：先被存储到缓冲区中，缓冲区满或者刷新时才输出到屏幕。

cout 可以使用重定向函数 freopen 进行重定向输出到文件中保存。

```cpp
/**
* 将 stream 按 mode 指定的模式重定向到路径 path 指向的文件
* 如果重定向时发生错误，则关闭原来的 stream，函数返回 NULL
* mode可以是“w”（写）或“T” （读）方式
*/
FILE * freopen(const char *path, const char *mode, FILE*stream);
```

标准输入输出重定向到文件

```cpp
#include <iostream>
using namespace std;

int main_out()
{
    int x, y;
    y = 10;
    // D:\soft\C\mingw64\bin
    freopen("StandardOutput.txt", "w", stdout);
    if (y == 0)
    {
        cerr << "Division by zero!";
    }
    else
    {
        // 上面通过freopen重定向了，cout会写入到StandardOutput.txt
        cout << "------------------" << x / y << endl;
    }
    return 0;
}

int main_in()
{
    int x, count, sum = 0;
    freopen("StandardOutput.dat", "r", stdin);
    for (count = 0; count < 10; count++)
    {
        // 输入流改为从文件StandardOutput.dat读取
        cin >> x;
        // 是否读取到文件的最后
        // cin.eof();
        sum += x;
    }
    cout << "前10个整数的平均值=" << 1.0 * sum / 10 << endl;
    return 0;
}
```

### 控制 IO 格式
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main_out()
{
    int x, y;
    y = 10;
    // D:\soft\C\mingw64\bin
    freopen("StandardOutput.txt", "w", stdout);
    if (y == 0)
    {
        cerr << "Division by zero!";
    }
    else
    {
        // 上面通过freopen重定向了，cout会写入到StandardOutput.txt
        cout << "------------------" << x / y << endl;
    }
    return 0;
}

int main_in()
{
    int x, count, sum = 0;
    freopen("StandardOutput.dat", "r", stdin);
    for (count = 0; count < 10; count++)
    {
        // 输入流改为从文件StandardOutput.dat读取
        cin >> x;
        // 是否读取到文件的最后
        // cin.eof();
        sum += x;
    }
    cout << "前10个整数的平均值=" << 1.0 * sum / 10 << endl;
    return 0;
}

int main_int()
{
    int n = 65535, m = 20;
    // 1)分别输出一个整数的十进制、十六进制和八进制表示
    cout << "1)" << n << "=" << hex << n << "=" << oct << n << endl;

    // 2)使用setbase分别输出一个整数的十进制、十六进制和八进制表示
    cout << "2)" << setbase(10) << m << "=" << setbase(16) << m << "=" << setbase(8) << m << endl;

    cout << "3)" << showbase; // 输出表示数值进制的前缀
    cout << setbase(10) << m << "=" << setbase(16) << m << "=" << setbase(8) << m << endl;
    return 0;
}

int main_float()
{
    double x = 1234567.89, y = 1.23456789;
    cout << "无格式控制：\t\t1)x=(" << x << "), y=(" << y << ")\n";

    cout << "保留5位有效数字：\t\t2)x=(" << setprecision(5) << x << "), y=(" << y << ")\n";

    cout << "保留小数点后5位：\t\t3)x=(" << fixed << setprecision(5) << x << "), y=(" << y << ")\n";

    cout << "科学计数法且保留小数点后5位：4)x=(" << x << "), y=(" << y << "\n";

    // 显示正负号、普通小数、宽度12、不够补默认右对齐，左边补 *
    cout << "5)" << showpos << fixed << setw(12) << setfill('*') << y << endl;

    // 非负数不显示正号，宽度为12，左对齐，右边补*（如果前面没有setfill(*)，则补空格符）
    cout << "6)" << noshowpos << setw(12) << left << y << endl;

    // 宽度12，宽度不足时右对齐，左边补字符
    cout << "7)" << setw(12) << right << y << endl;

    // 宽度不足时，负号和数值分列左右，中间用填充字符填充
    cout << "8)" << setw(12) << internal << -y << endl;

    return 0;
}

// setiosflags() 设置标志字进行格式控制
int main_setiosflags()
{
    /**
     * ios::skipws      跳过输入中的空白
     * ios::left        按输出左对齐，用填充字符填充右边
     * ios::right       按输出右对齐，用填充字符填充左边
     * ios::internal    在符号位或者基数指示符后填充
     * ios::dec *       十进制表示
     * ios::oct         八进制表示
     * ios::hex         十六进制表示
     * ios::showbase    显示基数指示符
     * ios::showpoint   显示小数点
     * ios::uppercase   使用大写字母表示十六进制数
     * ios::showpos     显示正负号
     * ios:scientific   科学计数法
     * ios::fixed       定点表示浮点数
     * ios::unitbuf     输出时刷新缓冲区
     */
    double x = 12.34;
    cout << "1)" << setiosflags(ios::scientific | ios::showpos) << x << endl;
    cout << "2)" << setiosflags(ios::fixed) << x << endl;
    cout << "3)" << resetiosflags(ios::fixed) << setiosflags(ios::scientific | ios::showpos)
         << x << endl;
    cout << "4)" << resetiosflags(ios::showpos) << x << endl;
    return 0;
}
```

### 调用 cout 成员函数
```cpp
#include <iostream>
using namespace std;

/**
 * precision()      控制保留有效数字
 * width()          控制输出宽度
 * fill()           设置填充字符
 * setf()           使用参数IFlags置位指定的标志位，返回值为置位前的标志字
 * unsetf()         清除参数IFlags指定的标志位，返回清除前的标志字
 */
int main()
{
    double values[] = {1.23, 20.3456, 300.4567, 4000.56789, 50000.1234567};
    cout.fill('*'); // 设置填充字符为星号*
    for (int i = 0; i < sizeof(values) / sizeof(double); i++)
    {
        cout << "values[" << i << "]=(";
        cout.width(10); // 设置输出宽度
        cout << values[i] << ")" << endl;
    }

    cout.fill(' '); // 设置填充字符为空格
    cout << endl;
    for (int i = 0; i < sizeof(values) / sizeof(double); i++)
    {
        cout << "values[" << i << "]=(";
        cout.width(10);        // 设置填充字符为空格
        cout.precision(i + 3); // 设置保留有效数字
        cout << values[i] << ")" << endl;
    }
}
```

### 调用 cin 成员函数
```cpp
#include <iostream>
using namespace std;
int main_get()
{
    int n = 0;
    char ch;
    while ((ch = cin.get()) != EOF)
    {
        // 当文件没有结束时继续进行循环
        // cin.get()功能类似C语言的getchar()，从键盘读入1个字符
        cout.put(ch);
        n++;
    }

    cout << "输入字符共计：" << n << endl;
    return 0;
}

int main()
{
    char buf[10];
    int i = 0;
    // 若输入流的一行超过9个字符，则会出错，循环结束
    while (cin.getline(buf, 10))
    {
        cout << ++i << ":" << buf << endl;
    }
    cout << "last:" << buf << endl;
    return 0;
}

/**
 * cin.eof()                        用于判断输入流是否已经结束。返回值为 true (1) 表示输入结束
 * cin.ignore(int n, char ch)       是跳过输入流中的 n 个字符，或跳过 ch 及其之前的所有字符
 * cin.peek()                       返回输入流中的当前字符，但是并不将该字符从输入流中取走
 */
```

## 文件操作
### 文件
根据文件数据的编码方式不同分为文本文件和二进制文件

+ 文本文件：文件中的每个字节都是一个 ASCII 码
+ 二进制文件：C++ 中将非文本文件统称为二进制文件

根据存取方式不同分为顺序存取文件和随机存取文件

+ 顺序存取文件：就是按照文件中数据存储次序进行顺序操作
+ 随机访问文件：是根据应用的需要，通过命令移动位置指针直接定位到文件内需要的位置并进行数据操作

### 文件打开模式标记
| 标记 | 说明 |
| --- | --- |
| ios::in | 以读的方式打开，不存在则报错 |
| ios::out | 以写的方式打开，不存在会新建 |
| ios::app | 追加，不存在会新建 |
| ios::ate | 打开一个已有的文件，并且将指针指向文件末尾，不存在则报错 |
| ios::trunc | 删除文件现有内容 |
| ios::binary | 以二进制的方式打开文件 |
| ios::in|ios::out | 打开已存在文件，即可读取又可写入，文件打开时原有内容不变，不存在则报错 |
| ios::in|ios::out|ios::trunc | 同上，打开文件会清除内容 |


### 读取&写入文本文件
```cpp
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
```

### 读取&写入二进制文件
```cpp
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
```

### 文本文件&二进制文件
文本文件

+ 优点：是具有较高的兼容性
+ 缺点
    - 是存储一批纯数值信息时，要在数据之间人为地添加分隔符
    - 在输入/输出过程中，系统要对内外存的数据格式进行相应的转换
    - 不便于对数据进行随机访问

二进制文件

+ 优点
    - 相同数据类型的数据所占空间的大小均是相同的，不必在数据之间人为地添加分隔符
    - 在输入/输出过程中，系统不需要对数据进行任何转换
    - 便于对数据实行随机访问
+ 缺点：数据兼容性差

> 通常纯文本信息（如字符串）以文本文件形式存储而将数值信息以二进制文件形式存储。文本文件和二进制文件在处理上和使用上有微小差别。
>

### 随机文件访问
+ 顺序文件：只能进行顺序存取操作的文件。如:键盘显示器和保存在磁带上的文件
+ 随机文件：可以在文件的任意位置进行存取操作文件如：磁盘文件
+ 顺序访问：严格按照数据保存的次序从头到尾访问文件
+ 随机访问：根据需要在文件的不同位置进行访问顺序文件只能进行顺序访问；随机文件既可以进行顺序访问，也可以进行随机访问
+ 文件位置指针：文件打开后，系统自动生成一个流指针，这个指针决定着写或读开始的位置

#### API
移动读指针函数

+ `istream & seekg(long pos);`将读指针设置为 pos，即将读指针移动到文件的 pos 字节处
+ `istream & seekg(long offset, ios::seek_dir dir);`将读指针按照 seek_dir 的指示（方向）移动 offset 个字节。其中 seek dir 是在类 ios 中定义的一个枚举类型
    - ios::beg：表示流的开始位置
    - ios::cur：表示流的当前位置
    - ios::end：表示流的结束位置

读指针当前位置值的函数

+ `long tellg();`函数返回值值为流中读指针的当前位置

移动写指针函数

+ `ostream & seekp (long pos);`写指针设置为pos即将写指针移动到文件的pos字节处
+ `ostream & seekp (long offset, ios::seek_dir dir);`写指针按 seek_dir 指示的方向移动offset个字节

返回写指针当前位置的函数

+ `long tellp();`函数返回值值为流中写指针的当前位置

```cpp
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
```

## 模版
### 函数模版
在程序设计时不给出相应数据的实际类型而是将类型参数化，在实际编译时，才由编译器利用实际的类型给予实例化，使它满足需要，就像按照模板来制造新的函数一样



函数模板 & 函数的区别

+ 函数模板本身在编译时不会生成任何目标代码，只有当通过模板生成具体的函数实例时才会生成目标代码
+ 被多个源文件引用的函数模板，应当连同函数体一同放在头文件中，而不能像普通函数那样只将声明放在头文件
+ 函数指针也只能指向模板的实例，而不能指向模板本身

```cpp
#include <iostream>
using namespace std;

// 函数模版
template <typename T>
T abs(T x)
{
    return x < 0 ? -x : x;
}

int main()
{
    cout << abs(-10) << endl;
    cout << abs(10.5) << endl;
    return 0;
}
```

定义对象交换的函数模板

```cpp
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
```

重载的函数与函数模板是允许重载的。在函数和函数模板名字相同的情况下，函数调用语句遵循以下先后顺序：

+ 先找参数完全匹配的普通函数（不是由模板实例化得到的模函）
+ 再找参数完全匹配的模板函数
+ 然后找实参经过自动类型转换后能够匹配的普通函数
+ 如果上面的都找不到，则报错

### 类模版
类是对一组对象的公共性质的抽象，而类模板则是对不同类的公共性质的抽象。（泛型类）

```cpp
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
```

普通参数的类模板

```cpp
#include <iostream>
using namespace std;

template <int i>
class TestClass
{
public:
    int buffer[i];
    int getData(int j);
};

template <int i>
int TestClass<i>::getData(int j)
{
    return *(buffer + j);
}

int main()
{
    TestClass<6> ClassInstF;
    int i;
    double fArr[6] = {12.1, 23.2, 34.3, 45.4, 56.5, 67.6};
    for (i = 0; i < 6; i++)
        ClassInstF.buffer[i] = fArr[i] - 10;
    for (i = 0; i < 6; i++)
    {
        double res = ClassInstF.getData(i);
        cout << res << " ";
    }
    cout << endl;
}
```

普通类继承类模版

```cpp
#include <iostream>
using namespace std;
template <class T> // 类模板
class TBase
{
    T data;

public:
    void print()
    {
        cout << data << endl;
    }
};

class Derived : public TBase<int> // 普通类Derived继承了模板类TBase<int>
{
};

int main()
{
    Derived d; // 生成派生类的对象，调用默认构造函数
    d.print(); // 调用成员函数，输出0
    return 0;
}
```

