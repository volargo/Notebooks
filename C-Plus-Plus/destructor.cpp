/*
 * =====================================================================================
 *
 *       Filename:  destructor.cpp
 *
 *    Description:  析构函数
 *
 *        Version:  1.0
 *        Created:  10/09/2017 06:12:22 PM
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
        Line(double);
        ~Line();

    private:
        double length;
};

Line::Line(double len): length(len)
{
    cout << "object is being, length = " << len << endl;
}

Line::~Line(void)
{
    cout << "object is being" << endl;
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
    line.setLength(50.0F);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;
}
