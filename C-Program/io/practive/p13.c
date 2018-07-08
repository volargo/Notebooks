/*
 * =====================================================================================
 *
 *       Filename:  p13.c
 *
 *    Description:  get character numbers at specify line in the text.
 *
 *        Version:  1.0
 *        Created:  07/29/2017 03:19:34 PM
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

#define Error(str) FatalError(str)
#define FatalError(str) (fprintf(stderr, "%s\n", str), exit(EXIT_FAILURE))

#define BUFFER_SIZE 256

int line_length(const char *filename, int n) {
    FILE *fp;
    char str[BUFFER_SIZE];
    long i = 0;

    // 需要检测文件是否可以打开
    if ((fp = fopen(filename, "rb")) == NULL) {
        Error("can't open file.");
    }

    // 需要定位文件位置到起始处, 并清除文件流错误指示器
    rewind(fp);
    while (fgets(str, sizeof(str), fp) != NULL) {
        i++;
        if (i == n) {
            // 需要关闭文件流, 避免流数量占用
            fclose(fp);
            return strlen(str);
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int n, length = -1;

    // 需要检测客户是否按照要求执行命令和参数的输入
    if (argc != 2) {
        Error("usage: command filename");
    }

    // 需要客户手动指定要在文本中查找的行号
    fprintf(stdout, "Enter search line numbers: ");
    scanf("%d", &n);

    // 需要调用line_length函数反馈查找结果
    if ((length = line_length(argv[1], n)) > 0) {
        fprintf(stdout, "Length was %d of this line in the '%s' file.\n", length, argv[1]);
    } else {
        Error("specify line not found.");
    }

    return 0;
}
