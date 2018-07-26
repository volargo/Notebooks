/*
 * =====================================================================================
 *
 *       Filename:  tgetpwuid.c
 *
 *    Description:  test getpwuid function from <pwd.h>
 *
 *        Version:  1.0
 *        Created:  08/21/2017 09:36:57 PM
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
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

int
main(void)
{
    struct passwd   *user_info;
        
    if ((user_info = getpwuid(getuid())) == NULL) {
        fprintf(stderr, "getpwuid error: ");
        perror(strerror(EBADRQC));
    }
    printf("user id: %d\n", user_info->pw_uid);
    
    return 0;
}
