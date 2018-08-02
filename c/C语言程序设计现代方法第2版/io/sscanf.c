/*
 * =====================================================================================
 *
 *       Filename:  sscanf.c
 *
 *    Description:  int sscanf(const char *str, const char *format, ...);
 *
 *        Version:  1.0
 *        Created:  07/28/2017 10:13:14 PM
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

#define MAX_LEN 50

int main(void)
{
    int month, year, day;

    char str[MAX_LEN + 1];

    fgets(str, sizeof(str), stdin);
    
    if (sscanf(str, "%d/%d/%d", &month, &day, &year) == 3) {
        fprintf(stdout, "Month: %d Day: %d Year: %d\n", month, day, year);
    }
    else if (sscanf(str, "%d-%d-%d", &month, &day, &year) == 3) {
        fprintf(stdout, "Month: %d Day: %d Year: %d\n", month, day, year);
    }
    else {
        fprintf(stdout, "Date not in the proper form.\n");
    }

    return 0;
}
