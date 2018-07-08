/*
 * =====================================================================================
 *
 *       Filename:  fcopy.c
 *
 *    Description:  复制文件
 *
 *        Version:  1.0
 *        Created:  07/27/2017 07:29:51 PM
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
    FILE *source_fp, *dest_fp;
    int ch;

    // 首先检测用户操作是否正确
    if (argc != 3) {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    // 检测源文件是否能读取
    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // 检测目标文件是否可写入
    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // 源文件和目标文件检测有效, 需要将源文件内容写入到目标文件
    while ((ch = getc(source_fp)) != EOF) {
        putc(ch, dest_fp);
    }

    // 关闭文件流
    fclose(source_fp);
    fclose(dest_fp);

    return 0;
}
