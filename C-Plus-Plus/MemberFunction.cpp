/*
 * =====================================================================================
 *
 *       Filename:  MemberFunction.cpp
 *
 *    Description:  C++类成员函数
 *
 *        Version:  1.0
 *        Created:  10/05/2017 06:58:01 PM
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

/*
 * 一个描述盒子的类
 */
class Box
{
    // 盒子的属性
    public:
        double      length;
        double      height;
        double      breadth;

        // 成员函数
        double  getVolume(void);
        void    setLength(double);
        void    setHeight(double);
        void    setBreadth(double);
};

double Box::getVolume(void)
{
    return (length * height * breadth);
}

void Box::setLength(double len)
{
    length = len;
}

void Box::setHeight(double hei)
{
    height = hei;
}

void Box::setBreadth(double bre)
{
    breadth = bre;
}

// 主程序执行入口
int main(void)
{
    Box     box1, box2;         // 声明三个Box类的对象
    double  volume = 0.0F;      // 存储体积

    // box1描述
    box1.setLength(6.0);
    box1.setHeight(7.0);
    box1.setBreadth(8.0);

    // box2描述
    box2.setLength(12.0);
    box2.setHeight(13.0);
    box2.setBreadth(14.0);

    // box1的体积
    volume = box1.getVolume();
    cout << "Box1's volume: " << volume << endl;

    // box2的体积
    volume = box2.getVolume();
    cout << "Box2's volume: " << volume << endl;

    return 0;
}
