/*
 * =====================================================================================
 *
 *       Filename:  InheritPrivate.cpp
 *
 *    Description:  private继承
 *
 *        Version:  1.0
 *        Created:  10/06/2017 03:47:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>
#include <assert.h>

using namespace std;

class A {
    public:
        int     a;

        A() {
            a1 = 1;
            a2 = 2;
            a3 = 3;
            a = 4;
        }

        void fun() {
            cout << a << endl;
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;
        }

    public:
        int     a1;
    protected:
        int     a2;
    private:
        int     a3;
};

class B : private A {
    public:
        int     a;

        B(int i) {
            A();
            a = i;
        }

        void fun() {
            cout << a << endl;
            cout << a1 << endl;
            cout << a2 << endl;
            cout << a3 << endl;     // error
        }
};

int main(void)
{
    B   b(10);

    cout << b.a << endl;
    cout << b.a1 << endl;   // error
    cout << b.a2 << endl;   // error
    cout << b.a3 << endl;   // error

    system("pause");

    return 0;
}
