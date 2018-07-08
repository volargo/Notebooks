/*
 * =====================================================================================
 *
 *       Filename:  enumtype.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 01:00:16 PM
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

int
main(void)
{
    enum color {
        red, 
        green, 
        blue, 
        yellow
    } car;
    car = green;

    switch (car) {
        case red:
            cout << "red car" << endl;
            break;
        case green:
            cout << "green car" << endl;
            break;
        case blue:
            cout << "blue car" << endl;
            break;
        case yellow:
            cout << "yellow car" << endl;
            break;
        default:
            cout << "unknow color for this car" << endl;
            break;
    }
    
    return 0;
}
