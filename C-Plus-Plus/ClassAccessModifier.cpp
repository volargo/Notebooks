/*
 * =====================================================================================
 *
 *       Filename:  ClassAccessModifier.cpp
 *
 *    Description:  C++类访问修饰符
 *
 *        Version:  1.0
 *        Created:  10/05/2017 07:22:06 PM
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
        double  length;
        
        void    setLength(double);
        double  getLength(void);
};

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
    Line    le;

    le.setLength(6.0);
    cout << "Length of le: " << le.getLength() << endl;

    return 0;
}
