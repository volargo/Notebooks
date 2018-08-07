/*
 * =====================================================================================
 *
 *       Filename:  uid_pid.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/07/2017 10:15:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int
main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());

    exit(0);
}
