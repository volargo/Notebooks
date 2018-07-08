/*
 * =====================================================================================
 *
 *       Filename:  explicit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2017 03:06:42 PM
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

class Test1 {
    public:
        Test1(int n) {
            num = n;
        } // 普通构造函数
    private:
        int num;
};

class Test2 {
    public:
        explicit Test2(int n) {
            num = n;
        } // 普通构造函数
    private:
        int num;
};

int
main(void)
{
    Test1 t1 = 12;

    // 下面的语句编译不能通过
    //   Test2 t2 = 13;

    return 0;
}
