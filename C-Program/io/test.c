/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/27/2017 08:04:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "FatalError.h"

int main(int argc, char *argv[])
{
    int ch;

    if (argc != 2) {
        FatalError("usage: fputs string");
    }

    fputs(argv[1], stdout);
    ch = '\n';
    putc(ch, stdout);

    return 0;
}
