/*
 * =====================================================================================
 *
 *       Filename:  fwrite.c
 *
 *    Description:  修改fcopy程序使用fread和fwrite实现文件复制
 *
 *        Version:  1.0
 *        Created:  07/30/2017 10:09:40 PM
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

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    char buffer[BUFFER_SIZE];
    FILE *source_fp, *dest_fp;
    int nums;

    if (argc != 3) {
        fprintf(stderr, "usage: command source dest.\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb+")) == NULL) {
        fprintf(stderr, "can't open file.\n");
        exit(EXIT_FAILURE);
    }

    if ((dest_fp = fopen(argv[2], "wb+")) == NULL) {
        fprintf(stderr, "can't open file.\n");
        exit(EXIT_FAILURE);
    }

    rewind(source_fp);
    while ((nums = fread(buffer, sizeof(char), BUFFER_SIZE, source_fp)) > 0) {
        fwrite(buffer, sizeof(char), nums, dest_fp);
    }

    return 0;
}
