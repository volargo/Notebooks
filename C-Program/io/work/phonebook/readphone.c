/*
 * =====================================================================================
 *
 *       Filename:  readphone.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/31/2017 11:08:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, char *argv[])
{
    FILE *fp;
    int i, ch, d1, d2, d3;
    char data[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "usage: command filenaem\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "can't open file.\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (isdigit(ch)) {
            data[i++] = ch;
            if (i == 10) {
                sscanf(data, "%3d%3d%4d", &d1, &d2, &d3);
                fprintf(stdout, "(%3d) %3d-%4d\n", d1, d2, d3);
                i = 0;
            }
        }
    }

    return 0;
}
