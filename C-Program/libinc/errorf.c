/*
 * =====================================================================================
 *
 *       Filename:  errorf.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/04/2017 06:40:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdarg.h>

int errorf(const char *format, ...) {
    static int num_errors = 0;
    va_list ap;
    int n;

    num_errors++;
    fprintf(stderr, "*** Error %d: ", num_errors);
    va_start(ap, format);
    n = vfprintf(stderr, format, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    return n;
}
