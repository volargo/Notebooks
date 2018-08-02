/*
 * =====================================================================================
 *
 *       Filename:  memcpy.c
 *
 *    Description:  memcpy()函数的使用
 *                  不可以在源和目的重叠时正常工作
 *
 *        Version:  1.0
 *        Created:  07/31/2017 06:28:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (imau), wood@khan.ren
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *source = "hola, sunflower girl.";
    char dest[strlen(source)];

    // void *memcpy(void *dest, const void *src, size_t n);
    memcpy(dest, source, strlen(source));
    fprintf(stdout, "dest: %s\n", dest);

#if 0
    // 源和目的有重叠, 行为未定义
    memcpy(source, source, strlen(source));
    fprintf(stdout, "source: %s\n", source);
#endif

    return 0;
}
