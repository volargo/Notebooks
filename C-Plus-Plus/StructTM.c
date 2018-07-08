/*
 * =====================================================================================
 *
 *       Filename:  tm.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/02/2017 11:28:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t  now = time(0);

    struct tm *f_time = localtime(&now);

    printf("年: %d\n", 1900+f_time->tm_year);
    printf("月: %d\n", f_time->tm_mon);
    printf("日: %d\n", f_time->tm_mday);
    printf("时间: %d:%d:%d\n", f_time->tm_hour, 
            f_time->tm_min, f_time->tm_sec);

    return 0;
}
