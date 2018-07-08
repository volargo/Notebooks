/*
 * =====================================================================================
 *
 *       Filename:  domain.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 01:31:30 PM
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

int     g = 99;

int     func(void);

int main(void)
{
    int     g = 9;

    cout << "local variable is: " << g << endl;

    int kk = func();
    cout << "global variable is: " << kk << endl;

    int     a = 1;
    
    {
        int     a = 2;
        cout << a << endl;
    }

    cout << a << endl;

    return 0;
}

int
func(void) {
    return g;
}
