/*
 * =====================================================================================
 *
 *       Filename:  invclear.c
 *
 *    Description:  块的输入/输出
 *
 *        Version:  1.0
 *        Created:  07/27/2017 11:20:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (), wood@khan.ren
 *   Organization:  imau
 *
 * =====================================================================================
 */
#include "FatalError.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_head;
} inventory[MAX_PARTS];

int num_parts;

int main(void)
{
    FILE *fp;
    int i;

    if ((fp = fopen("inventory.dat", "rb+")) == NULL) {
        FatalError("Can't open directory file.");
    }
    num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, fp);

    for (i = 0; i < num_parts; i++) {
        inventory[i].on_head = 0;
    }
    // 这里需要重新定位文件的开始处
    rewind(fp);
    fwrite(inventory, sizeof(struct part), num_parts, fp);
    fclose(fp);

    return 0;
}
