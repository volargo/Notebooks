/*
 * =====================================================================================
 *
 *       Filename:  constructor_argc.cpp
 *
 *    Description:  带参数的构造函数
 *
 *        Version:  1.0
 *        Created:  10/09/2017 05:37:18 PM
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

Line::Line(double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
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
    Line    line(10.0F);

    cout << "Length of line: " << line.getLength() << endl;
    line.setLength(20.0F);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;
}
