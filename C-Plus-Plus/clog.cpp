/*
 * =====================================================================================
 *
 *       Filename:  clog.cpp
 *
 *    Description:  标准日志流(clog)
 *
 *        Version:  1.0
 *        Created:  10/03/2017 05:48:15 PM
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
    char    str[] = "Unable read...";

    clog << "Error message: " << str << endl;

    return 0;
}
