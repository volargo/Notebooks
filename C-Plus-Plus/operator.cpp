/*
 * =====================================================================================
 *
 *       Filename:  operator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 06:54:26 PM
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
func1(void) {
    unsigned int a = 60;      // 60 = 0011 1100  
    unsigned int b = 13;      // 13 = 0000 1101
    int c = 0;           

    c = a & b;             // 12 = 0000 1100
    cout << "Line 1 - c 的值是 " << c << endl ;

    c = a | b;             // 61 = 0011 1101
    cout << "Line 2 - c 的值是 " << c << endl ;

    c = a ^ b;             // 49 = 0011 0001
    cout << "Line 3 - c 的值是 " << c << endl ;

    c = ~a;                // -61 = 1100 0011
    cout << "Line 4 - c 的值是 " << c << endl ;

    c = a << 2;            // 240 = 1111 0000
    cout << "Line 5 - c 的值是 " << c << endl ;

    c = a >> 2;            // 15 = 0000 1111
    cout << "Line 6 - c 的值是 " << c << endl ;

    return 0;
}

int
func2(void) {
    int a = 21;
    int c ;

    c =  a;
    cout << "Line 1 - =  运算符实例，c 的值 = : " <<c<< endl ;

    c +=  a;
    cout << "Line 2 - += 运算符实例，c 的值 = : " <<c<< endl ;

    c -=  a;
    cout << "Line 3 - -= 运算符实例，c 的值 = : " <<c<< endl ;

    c *=  a;
    cout << "Line 4 - *= 运算符实例，c 的值 = : " <<c<< endl ;

    c /=  a;
    cout << "Line 5 - /= 运算符实例，c 的值 = : " <<c<< endl ;

    c  = 200;
    c %=  a;
    cout << "Line 6 - %= 运算符实例，c 的值 = : " <<c<< endl ;

    c <<=  2;
    cout << "Line 7 - <<= 运算符实例，c 的值 = : " <<c<< endl ;

    c >>=  2;
    cout << "Line 8 - >>= 运算符实例，c 的值 = : " <<c<< endl ;

    c &=  2;
    cout << "Line 9 - &= 运算符实例，c 的值 = : " <<c<< endl ;

    c ^=  2;
    cout << "Line 10 - ^= 运算符实例，c 的值 = : " <<c<< endl ;

    c |=  2;
    cout << "Line 11 - |= 运算符实例，c 的值 = : " <<c<< endl ;

    return 0;
}

int main(void)
{
    func1();
    func2();

    return 0;
}
