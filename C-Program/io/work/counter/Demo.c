/*
 * =====================================================================================
 *
 *       Filename:  Demo.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/30/2017 07:12:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "CounterADT.h"

int main(int argc, char *argv[])
{
    int i, n = 0;
    FILE *fp;

    if (argc < 2) {
        Error("usage: command [argv] ...");
    }

    i = 1;
    while (i < argc) {
        fp = fopen(argv[i], "rb+");
        if (i == 1)
            printf("There is infomation about '%s':\n", argv[i]);
        else
            printf("\nThere is infomation about '%s':\n", argv[i]);
        print_info(fp, n);
        puts("");
        i++;
    }
    return 0;
}
