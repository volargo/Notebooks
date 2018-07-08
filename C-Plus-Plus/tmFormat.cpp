/*
 * =====================================================================================
 *
 *       Filename:  format_tm.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/2017 11:21:41 PM
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

int main(int argc, char *argv[])
{
    // 基于当前系统的时间/日期
    time_t  now = time(0);

    cout << "1970年到现在经过的秒数: " << now << endl;

    tm  *ltm = localtime(&now);

    cout << "年: " << 1900+ltm->tm_year << endl;
    cout << "月: " << 1 + ltm->tm_mon << endl;
    cout << "日: " << ltm->tm_mday << endl;
    cout << "时间: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    return 0;
}
