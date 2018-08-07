/*
 * =====================================================================================
 *
 *       Filename:  input.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/27/2017 06:31:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(void)
{
    char ch;
    FILE *fp = fopen("example.dat", "a+");

    // int fgetc(FILE *stream);
    ch = fgetc(fp);
    // int fputc(int c, FILE *stream);
    fputc(ch, stdout);

    // int getc(FILE *stream);
    ch = getc(fp);
    // int putc(int c, FILE *stream);
    putc(ch, stdout);

    ungetc(ch, fp);

    fclose(fp);
    return 0;
}
