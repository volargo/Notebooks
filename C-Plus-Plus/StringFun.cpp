/*
 * =====================================================================================
 *
 *       Filename:  str_fun.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2017 12:23:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string  http = "www.khan.ren";

    // length
    cout << "length of " << http << "is : " << http.length() << endl;

    // append
    http.append("/Linux");
    cout << http << endl;

    // delete
    int     pos = http.find("/Linux");      // search location of child string
    cout << pos << endl;
    http.replace(pos, sizeof("/Linux"), "");
    cout << http << endl;

    int     first = http.find_first_of(".");    // 从头开始寻找字符'.'的位置
    int     last = http.find_last_of(".");      // 从末尾开始寻找字符'.'的位置
    cout << http.substr(first + 1, last - first - 1) << endl;   // 提取子串并打印

    return 0;
}
