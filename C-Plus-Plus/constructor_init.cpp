/*
 * =====================================================================================
 *
 *       Filename:  constructor_init.cpp
 *
 *    Description:  使用初始化列表初始化字段
 *
 *        Version:  1.0
 *        Created:  10/09/2017 05:52:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

class Line
{
    public:
        void setLength(double);
        double getLength(void);
        Line(double);   // 带参数的构造函数

    private:
        double length;
};

// 使用初始化列表来初始化字段
Line::Line(double len): length(len)
{
    cout << "Object is being created, length = " << len << endl;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}

int main(void)
{
    Line    line(30.0F);

    cout << "Length of line: " << line.getLength() << endl;
    line.setLength(50.0F);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;
}
