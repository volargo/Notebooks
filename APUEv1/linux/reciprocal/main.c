/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/18/2017 10:56:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "reciprocal.hpp"

#define ERROR(str) ERRORFATAL(str)
#define ERRORFATAL(str) (fprintf(stdout, "%s\n", str), exit(0))

int
main(int argc, char *argv[])
{
    int     i;

#if 1
    // check argcument numbers
    if (argc != 2) {
        ERROR("usage: reciprocal <prefix>");
    }
#endif

    // check argcument is number
    i = atoi(argv[1]);
    printf("The reciprocal of %d is %g\n", i, reciprocal(i));
    exit(0);
}

