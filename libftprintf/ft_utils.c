/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:31:44 by uvadakku          #+#    #+#             */
/*   Updated: 2025/07/22 16:06:11 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int	ft_putchar_pf(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_pf(const char *str)
{
	int count;
	if (str == NULL)
		return (ft_putstr_pf("(null)")); // Handle null string case
	count = 0;
	while (*str)
	{ 
		count += ft_putchar_pf(*str++);
	}
	return (count);
}
int ft_putnbr(int n)
{
	int count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648"));
	if (n == 0)
		return (ft_putchar_pf('0'));
	if (n < 0)
	{ 
		count += ft_putchar_pf('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n /10); 
	count += ft_putchar_pf((n % 10) + '0'); 
	return (count);
}
int ft_putnbr_unsigned(unsigned int n)
{
    int count = 0;

    if (n >= 10)
        count += ft_putnbr_unsigned(n / 10); 
    count += ft_putchar_pf((n % 10) + '0'); 
    return (count);
}

int main (void)
{
	unsigned int num = 6789908;
	//int count_lower = ft_print_hexadecimal_lower(num);
	//int count_upper = ft_print_hexadecimal_upper(num);
    ft_putchar_pf('A');
    ft_putchar_pf('\n');
    ft_putstr_pf("hello world");
	ft_putchar_pf('\n');
	// Example usage of the hexadecimal printing functions
	ft_putchar_pf('\n');
	ft_putstr_pf("Lowercase hex count: ");
	//ft_putchar_pf(count_lower + '0');
	ft_putchar_pf('\n');
	ft_putstr_pf("Uppercase hex count: ");
	//ft_putchar_pf(count_upper + '0');
	ft_putchar_pf('\n');
	return 0;
}
