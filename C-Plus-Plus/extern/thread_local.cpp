/*
 * =====================================================================================
 *
 *       Filename:  thread_local.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 04:28:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>

thread_local int x;

class X {
    static thread_local std::string s;      // 类的static成员变量
};
static thread_local std::string X::s;       // X::s 是需要定义的

void
foo(void) {
    thread_local std::vector(int) v;        // 本地变量
}
