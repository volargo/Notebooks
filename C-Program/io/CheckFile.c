/*
 * =====================================================================================
 *
 *       Filename:  CheckFile.c
 *
 *    Description:  检测文件末尾和错误条件
 *
 *        Version:  1.0
 *        Created:  07/24/2017 08:23:21 PM
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

int find_int(const char *filename) {
    FILE *fp = fopen(filename, "r");
    int n;

    if (fp == NULL) {
        return -1;
    }

    while (fscanf(fp, "%d", &n) != 1) {
        if (ferror(fp)) {
            fclose(fp);
            return -2;
        }
        if (feof(fp)) {
            fclose(fp);
            return -3;
        }
        fscanf(fp, "%*[^\n]");
    }

    fclose(fp);
    return n;
}

int main(int argc, char *argv[])
{
    int error_num;
    FILE *fp = fopen("log.txt", "a+");

    if (argc != 2) {
        fprintf(stderr, "usage: filename.\n");
        exit(EXIT_FAILURE);
    }

    error_num = find_int(argv[1]);

    switch (error_num) {
        case -1:
            fprintf(stderr, "can't open file.\n");
            break;
        case -2:
            fprintf(stderr, "input error.\n");
            break;
        case -3:
            fprintf(stderr, "integer not found.\n");
            break;
        default:
            fprintf(fp, "open file success.\n");
            break;
    }
    fclose(fp);

    return 0;
}
