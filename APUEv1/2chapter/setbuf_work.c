/*
 * =====================================================================================
 *
 *       Filename:  tsetbuf.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/21/2017 09:24:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <sys/stat.h>

void my_setbuf(FILE *restrict fp, char *restrict buf) {
    if (buf == NULL) {
        setvbuf(fp, buf, _IONBF, 0);
    } else {
        struct stat fp_statbuf;

        fstat(fileno(fp), &fp_statbuf);
        if (S_ISCHR(fp_statbuf.st_mode)) {      /* man 2 stat */
            setvbuf(fp, buf, _IOLBF, BUFSIZ);
        } else {
            setvbuf(fp, buf, _IONBF, BUFSIZ);
        }
    }
}
