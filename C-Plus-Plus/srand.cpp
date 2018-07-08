/*
 * =====================================================================================
 *
 *       Filename:  srand.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 11:08:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>
#include <ctime>
#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
    int     i, j;

    srand( (unsigned)time(NULL) );

    /* 生成10个随机数 */
    for (i = 0; i < 10; i++) {
        // 生成实际的随机数
        j = rand();
        cout << "随机数字: " << j << endl;
    }

    return 0;
}
