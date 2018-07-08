/*
 * =====================================================================================
 *
 *       Filename:  string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2017 11:41:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char    greeting[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    cout << "Greeting message: ";
    cout << greeting << endl;

    char    str1[11] = "Hello";
    char    str2[11] = "World";
    char    str3[11];
    int     len;

    // 复制str1到str3
    strcpy(str3, str1);
    cout << "strcpy(str3, str1) : " << str3 << endl;

    // 拼接str1和str2
    strcat(str1, str2);
    cout << "strcat(str1, str3) : " << str1 << endl;

    // 拼接后的str1的长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;

    return 0;
}
