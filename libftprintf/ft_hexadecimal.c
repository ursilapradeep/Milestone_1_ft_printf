/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:46:10 by uvadakku          #+#    #+#             */
/*   Updated: 2025/07/25 14:12:45 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

int	ft_putnbr_hex(uintptr_t n, int uppercase)
{
	char	*base;
	int		count;
	int		ret;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		ret = ft_putnbr_hex(n / 16, uppercase);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar_pf(base[n % 16]);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	uintptr_t	address;
	int			count;
	int			ret;

	count = 0;
	address = (uintptr_t)ptr;
	if (!ptr)
	{
		ret = ft_putstr_pf("0x0");
		if (ret == -1)
			return (-1);
		return (ret);
	}
	ret = ft_putstr_pf("0x");
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_putnbr_hex(address, 0);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_print_hexadecimal(unsigned int n, int uppercase)
{
	int	count;

	if (n == 0)
		return (ft_putchar_pf('0'));
	count = ft_putnbr_hex(n, uppercase);
	return (count);
}

int	ft_print_hexadecimal_lower(unsigned int n)
{
	return (ft_print_hexadecimal(n, 0));
}

int	ft_print_hexadecimal_upper(unsigned int n)
{
	return (ft_print_hexadecimal(n, 1));
}
