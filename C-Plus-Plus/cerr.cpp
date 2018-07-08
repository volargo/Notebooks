/*
 * =====================================================================================
 *
 *       Filename:  cerr.cpp
 *
 *    Description:  标准错误流(cerr)
 *
 *        Version:  1.0
 *        Created:  10/03/2017 05:44:36 PM
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

    cerr << "Error message: " << str << endl;

    return 0;
}
