/*
 * =====================================================================================
 *
 *       Filename:  def_class.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/2017 05:42:35 PM
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
    public:
        double  length;
        double  breadth;
        double  height;
};

int main(void)
{
    Box     Box1;
    Box     Box2;

    Box1.length = 10.0F;
    cout << Box1.length << endl;

    Box2.height = 20.0F;
    cout << Box2.height << endl;

    return 0;
}
