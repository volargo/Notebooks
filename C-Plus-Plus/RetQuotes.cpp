/*
 * =====================================================================================
 *
 *       Filename:  ret_quotes.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2017 02:04:14 PM
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

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double&
setValues( int i ) {
    return vals[i];   // 返回第 i 个元素的引用
}

// 要调用上面定义函数的主函数
int main ()
{

    cout << "改变前的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }

    setValues(1) = 20.23; // 改变第 2 个元素
    setValues(3) = 70.8;  // 改变第 4 个元素

    cout << "改变后的值" << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }
    return 0;
}

int& func() {
   int q;
   //! return q; // 在编译时发生错误
   static int x;
   return x;     // 安全，x 在函数作用域外依然是有效的
}
