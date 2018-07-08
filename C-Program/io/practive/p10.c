/*
 * =====================================================================================
 *
 *       Filename:  p10.c
 *
 *    Description:  文件复制
 *
 *        Version:  1.0
 *        Created:  07/29/2017 02:14:18 PM
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

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int ch;

    if (argc != 3) {
        Error("usage: fcopy source dest.");
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        Error("can't open source file.");
    }

    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        Error("can't open dest file.");
    }

    while ((ch = getc(source_fp)) != EOF) {
        if (putc(ch, dest_fp) == EOF) {
            Error("Error during writing.");
        }
    }

    fclose(source_fp);
    fclose(dest_fp);

    return 0;
}
