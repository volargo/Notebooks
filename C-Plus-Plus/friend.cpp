/*
 * =====================================================================================
 *
 *       Filename:  friend.cpp
 *
 *    Description:  友元函数/友元类
 *
 *        Version:  1.0
 *        Created:  10/10/2017 09:19:41 AM
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

class Box
{
        double  width;

    public:
        friend void printWidth(Box box);
        void setWidth(double wid);
};

void Box::setWidth(double wid)
{
    width = wid;
}

// 友元函数, 但是不是类的成员函数
void printWidth(Box box)
{
    /* 友元函数访问该类的任何成员 */
    cout << "Width of box: " << box.width << endl;
}

int main(void)
{
    Box     box;

    box.setWidth(100.0F);

    printWidth(box);

    return 0;
}
