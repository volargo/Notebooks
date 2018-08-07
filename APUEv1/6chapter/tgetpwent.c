/*
 * =====================================================================================
 *
 *       Filename:  tgetpwent.c
 *
 *    Description:  test getpwent from <pwd.h>
 *
 *        Version:  1.0
 *        Created:  08/22/2017 01:31:10 PM
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
#include <pwd.h>

int
main(void)
{
    struct passwd   *pw_buf;

    /* 
     * after used getpwent function then must close file by endpwent function
     */
    pw_buf = getpwent();
    printf("user ID: %d\n", pw_buf->pw_uid);
    endpwent();

    exit(0);
}
