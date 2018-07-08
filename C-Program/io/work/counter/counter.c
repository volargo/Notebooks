/*
 * =====================================================================================
 *
 *       Filename:  counter.c
 *
 *    Description:  统计文本文件字符, 单词, 行的数量
 *
 *        Version:  1.0
 *        Created:  07/30/2017 05:52:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "CounterADT.h"

#define BUFFER_SIZE 1024

int is_error(FILE *stream) {
    if (stream == NULL) {
        if (feof(stream)) {
            fprintf(stderr, "End of file error.\n");
            return -1;
        } 
        if (ferror(stream)) {
            fprintf(stderr, "Reading of file error.\n");
            return -2;
        }
        else {
            fprintf(stderr, "Matching failure.\n");
            return -3;
        }
    }
    return 0;
}

int count_char(FILE *stream, int n) {
    int ch;

    if (!is_error(stream)) {
        rewind(stream);
        while ((ch = getc(stream)) != EOF) {
            n++;
        }
        return n;
    }
    exit(EXIT_FAILURE);
}

int count_word(FILE *stream, int n) {
    int ch, in_word;

    if (!is_error(stream)) {
        rewind(stream);
        in_word = 0;
        while ((ch = getc(stream)) != EOF) {
            if (isspace(ch)) {
                in_word = 0;
            }
            else if (!in_word) {
                in_word = 1;
                n++;
            }
        }
        return n;
    }
    exit(EXIT_FAILURE);
}

int count_line(FILE *stream, int n) {
    char str[BUFFER_SIZE];

    if (!is_error(stream)) {
        rewind(stream);
        while (fgets(str, sizeof(str), stream) != NULL) {
            n++;
        }
        return n;
    }
    exit(EXIT_FAILURE);
}

void print_info(FILE *stream, int n) {
    fprintf(stdout, "character numbers: %d, ", count_char(stream, n));
    fprintf(stdout, "word numbers: %d, ", count_word(stream, n));
    fprintf(stdout, "line numbers: %d.", count_line(stream, n));
    fclose(stream);
}
