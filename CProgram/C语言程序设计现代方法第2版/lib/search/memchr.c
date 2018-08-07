#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *p, str[] = "From follows function.";

    // void *memchr(const void *s, int c, size_t n);
    // 在搜索指定字符后停止搜索, 非遇到首个空字符停止
    p = memchr(str, 'f', sizeof(str));

    printf("%s\n", p);

    return EXIT_SUCCESS;
}
