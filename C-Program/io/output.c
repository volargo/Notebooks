#include <stdio.h>

// putchar()的宏实现
#define PUTCHAR(s) putc((s), stdout)

int main(void)
{
    char    ch, temp;
    FILE    *fp = fopen("foo", "a+");

    ch = getchar();
    // int putc(int c, FILE *stream);
    putc(ch, stdout);
    puts("");

    temp = getchar();
    // int fputc(int c, FILE *stream);
    fputc(temp, fp);

    fclose(fp);

    return 0;
}
