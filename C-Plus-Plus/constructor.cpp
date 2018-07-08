/*
 * =====================================================================================
 *
 *       Filename:  constructor.cpp
 *
 *    Description:  C++构造函数和析构函数
 *
 *        Version:  1.0
 *        Created:  10/09/2017 05:21:49 PM
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
        Line();     // 构造函数

    private:
        double length;
};

Line::Line(void)
{
    cout << "Object is being created" << endl;
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
    Line line;

    line.setLength(10.0F);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;
}
