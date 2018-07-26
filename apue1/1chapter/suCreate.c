/*
 * =====================================================================================
 *
 *       Filename:  su_create.c
 *
 *    Description:  系统调用创建新的文件, 没有分配权限, 需要以root身份执行代码
 *
 *        Version:  1.0
 *        Created:  08/10/2017 05:14:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int t1, t2;

    // use open function create newfile
    t1 = open("tfile1", O_WRONLY | O_CREAT | O_TRUNC, O_RDWR);
    // use create function create newfile
    t2 = creat("tfile2", O_RDWR);

    return 0;
}
