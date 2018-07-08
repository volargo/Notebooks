/*
 * =====================================================================================
 *
 *       Filename:  lambda.cpp
 *
 *    Description:  lambda 匿名函数
 
 *        Version:  1.0
 *        Created:  09/30/2017 07:32:47 PM
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

int main(int argc, char *argv[])
{
    int     num1 = 1;
    int     num2 = 2;
    int     num3 = 3;
    string  name = "Jack";

    auto    f = [num1, name](string str) mutable exception {
        name = "Jerry";

        cout << num1 << endl << name << endl << str << endl;
    };

    try {
        f("Your mom boom boom boom...");
    } catch (exception e) {
        cout << e.what() << endl;
    }

    return 0;
}

/*
   []      // 沒有定义任何变量。使用未定义变量会引发错误。
   [x, &y] // x以传值方式传入（默认），y以引用方式传入。
   [&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
   [=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
   [&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
   [=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
*/
