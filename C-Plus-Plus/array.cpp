/*
 * =====================================================================================
 *
 *       Filename:  array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2017 10:26:11 AM
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

#include <iomanip>
using std::setw;

int main(int argc, char *argv[])
{
    int     n[10];

    for (int i = 0; i < 10; i++) {
        n[i] = i + 100;
    }
    cout << "Element" << setw(13) << "Value" << endl;

    for (int j = 0; j < 10; j++) {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    return 0;
}
