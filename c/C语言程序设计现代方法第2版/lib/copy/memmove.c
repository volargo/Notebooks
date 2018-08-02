/*
 * =====================================================================================
 *
 *       Filename:  memmove.c
 *
 *    Description:  memmove()函数的使用
 *                  函数特性: 源和目的重叠时可以正常工作, memcpy不可以
 *
 *        Version:  1.0
 *        Created:  07/31/2017 06:35:30 PM
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

int main(void)
{
    char *source = "hola, sunflower girl.";
    char dest[strlen(source)];

    // void *memmove(void *dest, const void *src, size_t n);
    memmove(dest, source, (size_t)strlen(source));
    fprintf(stdout, "dest: %s\n", dest);

#if 0   // test next command when change this line 0 to 1
    // there working fine, no error.
    memmove(source, source, strlen(source));
#endif

    return EXIT_SUCCESS;
}
