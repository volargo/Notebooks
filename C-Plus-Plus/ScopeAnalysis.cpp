/*
 * =====================================================================================
 *
 *       Filename:  ScopeAnalysis.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/2017 06:39:43 PM
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

// 描述盒子的类
class Box
{
    public:
        double      length;
        double      height;

        // define member function of class
        double getVolume(void);
};

// 范围解析运算符在类的外部定义成员函数
double Box::getVolume(void)
{
    return (length * height);
}

int main(void)
{
    Box     box1;
    double  result;
    
    box1.length = 10.0F;
    box1.height = 5.0F;

    result = box1.getVolume();
    cout << result << endl;

    return 0;
}
