/*
 * =====================================================================================
 *
 *       Filename:  default_func_var.cpp
 *
 *    Description:  参数的默认值
 *
 *        Version:  1.0
 *        Created:  09/30/2017 07:18:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>

int
sum(int a, int b = 20) {
    int     result;

    result = a + b;

    return (result);
}

int main(void)
{
    // local variable
    int     a = 100;
    int     b = 200;
    int     result;

    // 调用函数来添加值
    result = sum(a, b);
    std::cout << "Total value is: " << result << std::endl;

    result = sum(a);
    std::cout << "Again total value is: " << result << std::endl;

    return 0;
}
