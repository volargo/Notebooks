/*
 * =====================================================================================
 *
 *       Filename:  ViewMemory.c
 *
 *    Description:  查看内存单元
 *
 *        Version:  1.0
 *        Created:  07/22/2017 12:49:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (LF), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include <ctype.h>
#include <stdio.h>

typedef unsigned char BYTE;

int main(void)
{
    unsigned int addr;
    int i, n;
    BYTE *ptr;

    printf("Address of main function: %x\n", (unsigned int) main);
    printf("Address of addr variable: %x\n", (unsigned int) &addr);
    printf("\nEnter a (hex) address: ");
    scanf("%x", &addr);
    printf("Enter number of bytes to view: ");
    scanf("%d", &n);

    printf("\n");
    printf("Address                 Bytes           Characters\n");
    printf("---------  ---------------------------  ------------");

    ptr = (BYTE *)addr;
    for (; n > 0; n -= 10) {
        printf("%8X  ", (unsigned int) ptr);
        for (i = 0; i < 10 && i < n; i++) {
            printf("%.2X ", *(ptr + i));
        }
        for (; i < 10; i++) {
            printf("    ");
        }
        printf("    ");
        for (i = 0; i < 10 && i < n; i++) {
            BYTE ch = *(ptr + i);
            if (!isprint(ch)) {
                ch = '.';
            }
            printf("%c", ch);
        }
        printf("\n");
        ptr += 10;
    }

    return 0;
}
