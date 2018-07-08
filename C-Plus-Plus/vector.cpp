/*
 * =====================================================================================
 *
 *       Filename:  vector.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2017 10:44:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vec;
    int i;

    cout << "vector size: " << vec.size() << endl;

    // 对向量vec追加5个整数
    for (i = 0; i < 5; i++) {
        /*
         * push_back(vector)函数原型: void push_back( const TYPE &val );
         * push_back(vector)函数描述: 添加值为val的值到当前vector末尾
         */
        vec.push_back(i);
    }
    
    cout << "extended vector size = " << vec.size() << endl;

    return 0;
}
