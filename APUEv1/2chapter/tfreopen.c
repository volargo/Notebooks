/*
 * =====================================================================================
 *
 *       Filename:  tfreopen.c
 *
 *    Description:  test freopen function from <stdio.h>
 *
 *        Version:  1.0
 *        Created:  08/19/2017 08:35:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#define Error(str)  FatalError(str)
#define FatalError(str) (fprintf(stderr, "%s\n", str), exit(EXIT_FAILURE))

int
main(int argc, char *argv[])
{
    FILE    *fp;

    if (argc < 2) {
        FatalError("usage: command file");
    }

    if ((fp = freopen(argv[1], "rb+", stdout)) == NULL) {
        FatalError("usage: freopen error");
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}
