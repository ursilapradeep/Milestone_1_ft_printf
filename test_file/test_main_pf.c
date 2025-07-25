#include "../libftprintf/ft_printf.h"

#include <stdio.h>

int	main(void)
{
    ft_printf("%c Hello, %s! Your score is %d out of %u.\n", 'I', "Ursila", 85, 100);
    ft_printf("Hex lower: %x, Hex upper: %X, Pointer: %p\n", 255, 255, &main);
    ft_printf("Print a percent sign: %%\n");
    return (0);
}