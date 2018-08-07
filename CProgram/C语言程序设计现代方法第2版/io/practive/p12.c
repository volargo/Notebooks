/*
 * =====================================================================================
 *
 *       Filename:  p12.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/29/2017 03:09:18 PM
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
    FILE *fp;
    int n = 0, ch;

    if (argc != 2) {
        fprintf(stderr, "usage: command filename");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) != NULL) {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '.') {
                n++;
            }
        }
        fclose(fp);
    }

    return 0;
}
