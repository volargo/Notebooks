/*
 * =====================================================================================
 *
 *       Filename:  constant.cpp
 *
 *    Description:  常量(字面量)
 *
 *        Version:  1.0
 *        Created:  09/30/2017 01:55:21 PM
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

int main(void)
{
    const unsigned long int A = 10ul;
    cout << A << endl;

    const double D = 3.14159E-5L;
    cout << D << endl;

    const wchar_t C = 'x';
    cout << C << endl;

    return 0;
}
