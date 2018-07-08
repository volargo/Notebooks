/*
 * =====================================================================================
 *
 *       Filename:  quotes.cpp
 *
 *    Description:  C++引用
 *
 *        Version:  1.0
 *        Created:  10/01/2017 01:51:27 PM
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

void swap(int&, int&);

int main(void)
{
    int     i;
    double  d;

    int&    r = i;
    double& s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r << endl;

    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s << endl;

#if 1
    int     a = 10;
    int     b = 100;
    
    cout << a << endl;
    cout << b << endl;

    swap(a, b);
    cout << a << endl;
    cout << b << endl;
#endif

#if 1
    int     rats1 = 10;
    int&    rats_quote = rats1;

    int     rats2 = 10000000;
    int*    const ptr = &rats2;
    cout << *ptr << endl;
#endif

    return 0;
}

void
swap(int& x, int& y) {
    int     temp;
    temp = x;
    x = y;
    y = temp;

    return;
}
