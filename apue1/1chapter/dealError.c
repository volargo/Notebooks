/*
 * =====================================================================================
 *
 *       Filename:  deal_error.c
 *
 *    Description:  how to use strerror() and perror() function
 *
 *        Version:  1.0
 *        Created:  08/07/2017 09:37:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <errno.h>

int
main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}
