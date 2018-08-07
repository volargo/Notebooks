/*
 * =====================================================================================
 *
 *       Filename:  indexof.c
 *
 *    Description:  线性查找 
 *
 *        Version:  1.0
 *        Created:  07/31/2018 11:03:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Volargo (VL), git@volargo.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int indexof(char* str, char letter)
{
        int     i = 0;
        while (str[i] != '\0') {
                if (str[i] == letter) {
                        return i;
                }
                i++;
        }
        return -1;
}

int main(void)
{
        char*   str = "Hello, World";

        if (indexof(str, 'a') != -1) {
                printf("found it.\n");
        } else {
                printf("not found.\n");
        }

        return 0;
}
