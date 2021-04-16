#include <stdio.h>

static int custom_cube(int addr)
{
    int cube;
    
    asm volatile (
       ".insn r 0x7b, 6, 6, %0, %1, x0"
             :"=r"(cube)
             :"r"(addr)
     );
    
    return cube; 
}

void main()
{
    int a = 3;
    int ret = 0;
    ret = custom_cube((int)&a);
    if(ret == a*a*a)
    {
        putchar('o');
        putchar('k');
    }
    else
    {
        putchar('e');
        putchar('r');
        putchar('r');
    }

    while(1);
}
