/*
 * =====================================================================================
 *
 *       Filename:  golable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 01:44:31 PM
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

int g = 10;

void
func1(int a, int b) {
    g = a + b;
    cout << "被改变的全局变量: " << g << endl;
}

void
func2(void) {
    cout << "此时的全局变量值: " << g << endl;
}

int main(void)
{
    func2();
    func1(10, 20);
    func2();
    
    return 0;
}
