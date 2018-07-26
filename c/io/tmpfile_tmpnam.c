/*
 * =====================================================================================
 *
 *       Filename:  tempfile.c
 *
 *    Description:  tmpfile(), tmpnam()函数: 临时文件
 *
 *        Version:  1.0
 *        Created:  07/23/2017 01:03:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp, *tempptr;
    char filename[L_tmpnam];

    if (argc != 2) {
        fprintf(stderr, "usage: canopen filename.");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r+")) == NULL) {
        fprintf(stderr, "%s can't opened.\n", argv[1]);
    }

    // FILE *tmpfile(void);
    tempptr = tmpfile();
    // char *tmpnam(char *s);
    tmpnam(filename);

    fclose(fp);
    fclose(tempptr);

    return 0;
}
