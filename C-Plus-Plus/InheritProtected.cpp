/*
 * =====================================================================================
 *
 *       Filename:  InheritProtected.cpp
 *
 *    Description:  protected继承
 *
 *        Version:  1.0
 *        Created:  10/06/2017 03:29:42 PM
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

class B : protected A {
    public:
        int     a;

        B(int i) {
            A();
            a = i;
        }

        void fun() {
            cout << a << endl;      // right, member of public
            cout << b.a1 << endl;   // error, protected can't be accessed outside the class
            cout << b.a2 << endl;   // error, protected can't be accessed outside the class
            cout << b.a3 << endl;   // error, private can't be derived classes to access base class members
        }
};

int main(void)
{
    B   b(10);

    cout << b.a << endl;    // right, member of public
    cout << b.a1 << endl;   // error, member of protected can't be accessed outside the class
    cout << b.a2 << endl;   // error, member of protected can't be accessed outside the class
    cout << b.a3 << endl;   // error, member of private can't be accessed outside the class
    
    system("pause");

    return 0;
}
