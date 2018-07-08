/*
 * =====================================================================================
 *
 *       Filename:  this_poniter.cpp
 *
 *    Description:  this指针
 *
 *        Version:  1.0
 *        Created:  10/10/2017 07:21:46 PM
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
    public:
        // 构造函数
        Box(double l = 2.0, double b = 2.0, double h = 2.0) {
            cout << "Constructor called." << endl;
            length = l;
            breadth = b;
            height = h;
        }

        // 普通成员函数
        inline double Volume() {
            return length * breadth * height;
        }

        // 普通成员函数
        inline int compare(Box box) {
            // this指针(指向类自己的指针)
            return this->Volume() > box.Volume();
        }

    private:
        double length;  // Length of box
        double breadth; // Breadth of box
        double height;  // Height of box
};

int main(void)
{
    Box     box1(3.3, 1.2, 1.5);    // Declare box1
    Box     box2(8.5, 6.0, 2.0);    // Declare box2

    if (box1.compare(box2)) {
        cout << "Box2 is smaller than box1" << endl;
    } else {
        cout << "Box2 is equal to or larger than box1" << endl;
    }

    return 0;
}
