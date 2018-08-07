/*
 * =====================================================================================
 *
 *       Filename:  tgetgrnam.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/06/2017 09:08:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "apue.h"
#include <grp.h>

int
main(void)
{
    struct group *grp_buf;

    grp_buf = getgrnam("Khan");

    fprintf(stdout, "%s\n", grp_buf->gr_passwd);

    exit(0);
}
