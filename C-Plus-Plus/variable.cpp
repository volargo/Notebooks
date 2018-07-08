/*
 * =====================================================================================
 *
 *       Filename:  variable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 01:16:58 PM
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

extern int      a, b;
extern int      c;
extern float    f;

int
main(void)
{
    // define variable
    int     a, b;
    int     c;
    float   f;

    // initialization variable
    a = 10;
    b = 20;
    c = a + b;
    cout << c << endl;

    f = 70.0 / 3.0;
    cout << f << endl;

    return 0;
}
