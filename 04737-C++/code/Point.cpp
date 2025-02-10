class Point
{
private:
    int x;
    int y;

public:
    void setXY(int a, int b);
    int getX();
    void draw();
};

// 成员函数
void Point::setXY(int a, int b)
{
    x = a;
    y = b;
}

// 内联函数
inline int Point::getX()
{
    return x;
}