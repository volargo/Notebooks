/*
 * =====================================================================================
 *
 *       Filename:  getopt_long.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2017 12:07:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "getopt_long.h"

/* 
 * let program manual output standard output or standard error,
 * and use EXIT_CODE exit program,
 * no return.
 */
void
print_usage (FILE* stream, int exit_code, const char* program_name) {
    fprintf(stream, "Usage: %s option [ inputfile... ]\n", program_name);
    fprintf(stream,
            "   -h --help Display this usage information.\n"
            "   -o --output Filename write output to file.\n"
            "   -v --verbose Print verbose message.\n");
    exit(exit_code);
}
