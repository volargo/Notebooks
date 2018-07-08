/*
 * =====================================================================================
 *
 *       Filename:  inline.cpp
 *
 *    Description:  内联函数
 *
 *        Version:  1.0
 *        Created:  10/10/2017 06:37:42 PM
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

inline int max(int x, int y)
{
    return (x > y ? x : y);
}

int main(void)
{
    cout << "Max (20,10): " << max(20, 10) << endl;
    
    return 0;
}
