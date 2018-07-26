/*
 * =====================================================================================
 *
 *       Filename:  prav16.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/22/2017 01:57:21 PM
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
typedef unsigned short WORD;
typedef unsigned long DWORD;

union reg_variable {
    struct {
        DWORD eax, ebx, ecx, edx;
    } dword;

    struct {
        union {
            WORD ax, bx, cx, dx;
            BYTE al, ah, bl, bh, cl, ch, dl, dh;
        } uword;
    } word;

    struct {
        union {
            BYTE al, ah, bl, bh, cl, ch, dl, dh;
        } ubyte;
    } byte;
} regs;
