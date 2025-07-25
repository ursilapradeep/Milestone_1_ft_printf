/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:31:44 by uvadakku          #+#    #+#             */
/*   Updated: 2025/07/25 14:12:50 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_putchar_pf(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr_pf(const char *str)
{
	int	count;
	int	ret;

	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		ret = ft_putchar_pf(*str++);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

int	ft_putnbr_pf(long n)
{
	int		count;
	int		ret;

	count = 0;
	if (n < 0)
	{
		ret = ft_putchar_pf('-');
		if (ret == -1)
			return (-1);
		count += ret;
		n = -n;
	}
	if (n >= 10)
	{
		ret = ft_putnbr_pf(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar_pf((n % 10) + '0');
	if (ret == -1)
		return (-1);
	return (count + ret);
}

int	ft_putnbr_unsigned_pf(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putnbr_unsigned_pf(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar_pf((n % 10) + '0');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
