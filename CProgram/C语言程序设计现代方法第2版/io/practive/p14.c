/*
 * =====================================================================================
 *
 *       Filename:  p14.c
 *
 *    Description:  realize 'fputs' and 'fgets' functions
 *
 *        Version:  1.0
 *        Created:  07/29/2017 09:23:00 PM
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
#include <string.h>

#define MAX_LEN 256

// fgets()函数的实现
char *fget_str(char *s, int n, FILE *stream) {
    int ch, len = 0;

    while (len < n - 1) {
        if ((ch = getc(stream)) == EOF) {
            if (len == 0 || ferror(stream)) {
                return NULL;
            }
            break;
        }
        s[len++] = ch;
        if (ch == '\n') {
            break;
        }
    }
    s[len] = '\0';
    return s;
}

// fputs()函数的实现
int fput_str(const char *s, FILE *stream) {
    while (*s != '\0') {
        if (putc(*s, stream) == EOF) {
            return EOF;
        }
        s++;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char str[MAX_LEN];

    if (argc != 2) {
        fprintf(stderr, "usage: command stream\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "ab+")) == NULL) {
        fprintf(stderr, "can't open file.\n");
        exit(EXIT_FAILURE);
    }

    rewind(fp);
    fget_str(str, sizeof(str), stdin);
    fput_str(str, fp);
    str[strlen(str) + 1] = '\0';

    fclose(fp);
    return 0;
}
