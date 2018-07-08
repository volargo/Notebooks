/*
 * =====================================================================================
 *
 *       Filename:  toupper.c
 *
 *    Description:  将文件中的字母字符转换为大写字母
 *
 *        Version:  1.0
 *        Created:  07/30/2017 05:11:38 PM
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

int main(int argc, char *argv[])
{
    int i, ch;
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "usage: command [argv] ...\n");
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (i++ < argc - 1) {
        if ((fp = fopen(argv[i], "rb")) == NULL) {
            fprintf(stderr, "%s can't be opened.\n", argv[i]);
            exit(EXIT_FAILURE);
        } else {
            fprintf(stdout, "This is '%s' content: \n", argv[i]);
            while ((ch = getc(fp)) != EOF) {
                // 转换小写可以使用towlower()函数
                putchar(toupper(ch));
            }
            fclose(fp);
        }
    }

    return 0;
}
