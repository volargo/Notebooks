/*
 * =====================================================================================
 *
 *       Filename:  complex_struct.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/28/2018 03:32:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

struct complex_struct {
    double x, y;
};

struct complex_struct
add_complex(struct complex_struct z1, struct complex_struct z2)
{
    z1.x = z1.x + z2.x;
    z1.y = z1.y + z2.y;

    return z1;
}

/*
 * main
 */
int main(void)
{
    struct complex_struct z;
    
    double x = 3.0;
    z.x = x;
    z.y = 4.0;

    if (z.y < 0)
        printf("z = %f%fi\n", z.x, z.y);
    else
        printf("z = %f + %fi\n", z.x, z.y);

    struct complex_struct z2 = z;
    z2 = add_complex(z2, z2);
    printf("z2 = %f + %fi\n", z2.x, z2.y);

    return 0;
}
