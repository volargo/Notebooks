/*
 * =====================================================================================
 *
 *       Filename:  static.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 04:01:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>

void func(void);

static int count = 10;  // golbal variable

int
main(void)
{
    while (count--) {
        func();
    }

    return 0;
}

void
func(void) {
    static int i = 5;   // local static variable
    i++;
    std::cout << "变量 i 为" << i;
    std::cout << ", 变量 count 为" << count << std::endl;
}
