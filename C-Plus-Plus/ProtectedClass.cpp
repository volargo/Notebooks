/*
 * =====================================================================================
 *
 *       Filename:  protected_class.cpp
 *
 *    Description:  访问修饰符protected
 *
 *        Version:  1.0
 *        Created:  10/06/2017 01:41:52 PM
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

class Box {
    protected:
        double  width;
};

// SmallBox是派生类
class SmallBox:Box {
    public:
        void    setSmallWidth(double);
        double  getSmallWidth(void);
};

double SmallBox::getSmallWidth(void) {
    return width;
}

void SmallBox::setSmallWidth(double wid) {
    width = wid;
}

// 主程序入口
int main(void)
{
    SmallBox    box;

    box.setSmallWidth(10.0F);
    cout << "Width of box: " << box.getSmallWidth() << endl;

    return 0;
}
