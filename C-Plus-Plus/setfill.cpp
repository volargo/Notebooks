/*
 * =====================================================================================
 *
 *       Filename:  setfill.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2017 11:11:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>
#include <iomanip>      // include setfill() and setw()

using namespace std;

int main(void)
{
    /*
     * setfill用来控制输出间隔字符填充
     */
    for (int i = 1; i < 10; i++) {
        cout << setfill('*') << setw(i) << '*' << endl;
    }

    return 0;
}
