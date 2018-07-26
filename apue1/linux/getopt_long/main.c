/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2017 11:58:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include "getopt_long.h"

const char* program_name;

int
main(int argc, char *argv[])
{
    int     next_option;

    const char* const short_option = "ho:v";

    const struct option long_option[] = {
        {"help", 0, NULL, 'h'},
        {"output", 1, NULL, 'o'},
        {"vebose", 0, NULL, 'v'},
        {NULL, 0, NULL, 0}  //数组末尾需要这样一个数组
    };

    /* 用于接受程序输出的文件名, 如果为NULL则表示为标准输出 */
    const char* output_filename = NULL;

    /* 是否显示冗余信息? */
    int     verbose = 0;

    /* 记住程序的名字, 可以用于输出的信息. 名字保存在argv[1]中 */
    program_name = argv[0];

    do {
        next_option = getopt_long(argc, argv, short_option, long_option, NULL);

        switch (next_option) {
            case 'h':
                print_usage(stdout, 0, program_name);
                break;
            case 'o':
                output_filename = optarg;
                break;
            case 'v':
                verbose = 1;
                break;
            case '?':
                print_usage(stderr, 1, program_name);
            case -1:
                break;
            default:
                abort();
        }
    } while (next_option != -1);

    if (verbose) {
        int i;
        for (i = optind; i < argc; ++i) {
            printf("Argument: %s\n", argv[i]);
        }
    }

    exit(0);
}
