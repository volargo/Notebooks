/*
 * =====================================================================================
 *
 *       Filename:  snprintf.c
 *
 *    Description:  int snprintf(char *str, size_t size, const char *format, ...);
 *
 *        Version:  1.0
 *        Created:  07/28/2017 09:58:56 PM
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

#define Error(str) FatalError(str)
#define FatalError(str) (fprintf(stderr, "%s\n", str), exit(EXIT_FAILURE))

#define NAME_LEN 50

int main(void)
{
    char name[NAME_LEN + 1];

    if (snprintf(name, NAME_LEN, "%s %s", "Alan", "Khan") < 0) {
        FatalError("use snprintf error.");
    }

    fprintf(stdout, "%s\n", name);

    return 0;
}
