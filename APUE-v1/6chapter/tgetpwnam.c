/*
 * =====================================================================================
 *
 *       Filename:  tgetpwnam.c
 *
 *    Description:  test tgetpwnam function from <pwd.h>
 *
 *        Version:  1.0
 *        Created:  08/21/2017 10:00:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

struct passwd *
my_getpwnam(const char *name) {
    struct passwd   *ptr;
    setpwent();
    while ((ptr = getpwent()) != NULL) {
        if (strcmp(name, ptr->pw_name) == 0) {
            break;      /* found a match */
        }
    }
    endpwent();     /* ptr is NULL if no match found */
    return(ptr);
}
