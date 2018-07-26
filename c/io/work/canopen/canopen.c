/*
 * =====================================================================================
 *
 *       Filename:  canopen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/30/2017 03:29:51 PM
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

int main(int argc, char *argv[])
{
    int i;
    FILE *fp;

    i = 1;
    if (argc < 2) {
        fprintf(stderr, "usage: command [f1] [f2] ...\n");
        exit(EXIT_FAILURE);
    }
    while (i < argc) {
        if ((fp = fopen(argv[i], "rb")) == NULL) {
            fprintf(stdout, "'%s' can't be opened.\n", argv[i]);
            exit(EXIT_FAILURE);
        } else {
            fprintf(stdout, "'%s' can be opened.\n", argv[i]);
            fclose(fp);
            i++;
        }
    }

    return 0;
}
