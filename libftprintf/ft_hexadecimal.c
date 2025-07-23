/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:46:10 by uvadakku          #+#    #+#             */
/*   Updated: 2025/07/22 19:12:39 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.c"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

int ft_putnbr_hex(unsigned int n, int uppercase)
{
	char	*base;
	int		count;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putnbr_hex(n / 16, uppercase);
	count += ft_putchar_pf(base[n % 16]);
	return (count);
}
int ft_print_pointer(void *ptr)
{
	unsigned long	address;
	int				count;
	address = (unsigned long)ptr;  
	count = ft_putstr_pf("0x");
	count += ft_putnbr_hex(address, 0); // call ft_putnbr_hex to print the address in hexadecimal format
	return (count); 
}

int ft_print_hexadecimal(unsigned int n, int uppercase)
{
	int count;
	if (n == 0)
		return (ft_putchar_pf('0')); //ifits hexadecimal 0 then prints '0'.
	count = ft_putnbr_hex(n, uppercase);
	return (count);
}

int ft_print_hexadecimal_lower(unsigned int n)
{
	return ft_print_hexadecimal(n, 0);
}

int	ft_print_hexadecimal_upper(unsigned int n)
{
	return ft_print_hexadecimal(n, 1);
}
