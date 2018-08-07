/*
 * =====================================================================================
 *
 *       Filename:  tstdarg.c
 *
 *    Description:  <stdarg.h>可变参数
 *
 *        Version:  1.0
 *        Created:  08/04/2017 05:32:23 PM
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

int max_int(int n, ...) {
    va_list ap;
    int i, current, largest;

    va_start(ap, n);
    largest = va_arg(ap, int);

    for (i = 0; i < n; i++) {
        current = va_arg(ap, int);
        if (current > largest) {
            largest = current;
        }
    }

    va_end(ap);
    return largest;
}

int main(void) {
    int max;
    
    max = max_int(3, 10, 20, 30);
    printf("max numbers was: %d\n", max);

    return 0;
}

#if 0

va_start();
va_arg();
va_end();

#endif
