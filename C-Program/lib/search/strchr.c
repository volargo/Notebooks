#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *p, s[] = "hola, sunflower girl.";

    p = strchr(s, 'h');
    fprintf(stdout, "%s\n", p);

    return EXIT_SUCCESS;
}
