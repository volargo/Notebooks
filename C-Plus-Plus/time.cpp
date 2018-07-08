/*
 * =====================================================================================
 *
 *       Filename:  time.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/01/2017 04:14:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
    // 基于当前系统的时间
    time_t  now = time(0);

    // 将系统时间转换为可见字符串形式
    char*   dt = ctime(&now);
    cout << "本地日期时间: " << dt << endl;

    tm      *gm_time = gmtime(&now);
    dt = asctime(gm_time);
    cout << "UTC 日期时间: " << dt << endl;

    return 0;
}
