/*
 * =====================================================================================
 *
 *       Filename:  tsetjmp.c
 *
 *    Description:  tests setjmp/longjmp
 *
 *        Version:  1.0
 *        Created:  08/04/2017 03:27:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf env;

void f1(void);
void f2(void);

int main(void)
{
    if (setjmp(env) == 0) {
        printf("setjmp returned 0\n");
    } else {
        printf("Program terminaters: longjmp called.\n");
        return 0;
    }

    f1();
    printf("Program terminaters normally.\n");
    return 0;
}

void f1(void) {
    printf("f1 begins\n");
    f2();
    printf("f2 begins\n");
}

void f2(void) {
    printf("f2 begins\n");
    longjmp(env, 1);
    printf("f2 returns\n");
}
