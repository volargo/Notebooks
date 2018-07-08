/*
 * =====================================================================================
 *
 *       Filename:  type.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 12:52:29 PM
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
    cout << "size of short: " << sizeof(short) << endl;
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of long int: " << sizeof(long int) << endl;
    cout << "size of float: " << sizeof(float) << endl;
    cout << "size of double: " << sizeof(double) << endl;
    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of string: " << sizeof(string) << endl;
    cout << "size of wchar_t: " << sizeof(wchar_t) << endl;

    return 0;
}
