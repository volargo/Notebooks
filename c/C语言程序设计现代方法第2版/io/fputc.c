/*
 * =====================================================================================
 *
 *       Filename:  fputc.c
 *
 *    Description:  输出函数
 *
 *        Version:  1.0
 *        Created:  07/27/2017 07:45:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;

    if (argc != 2) {
        fprintf(stderr, "usage: fputs filename");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open file.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        fputc(ch, stdout);
    }

    fclose(fp);

    return 0;
}
