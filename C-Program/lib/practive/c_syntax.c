/*
 * =====================================================================================
 *
 *       Filename:  c_syntax.c
 *
 *    Description:  检测C语言标识符是否合法
 *
 *        Version:  1.0
 *        Created:  08/03/2017 05:11:00 PM
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
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 20

int main(int argc, char *argv[])
{
    unsigned long i;
    char str[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "usage: command string");
        exit(EXIT_SUCCESS);
    }

    if (strlen(argv[1]) > BUFFER_SIZE) {
        fprintf(stderr, "buffer less than argv[1] length.\n");
        exit(EXIT_SUCCESS);
    }
    strncpy(str, argv[1], strlen(argv[1]));

    for (i = 1; i < strlen(argv[1]); i++) {
        if (isalpha(str[0]) || str[0] == '_') {
            if (isalnum(str[i]) || str[i] == '_')  {
                ;
            } else {
                fprintf(stderr, "syntax error.\n");
                exit(EXIT_SUCCESS);
            }
        }
        else {
            fprintf(stderr, "syntax error.\n");
            exit(EXIT_SUCCESS);
        }
    }
    printf("syntax right.\n");

    return EXIT_SUCCESS;
}
