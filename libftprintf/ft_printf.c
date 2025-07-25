/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:28:35 by uvadakku          #+#    #+#             */
/*   Updated: 2025/07/25 14:12:48 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>

int	handle_char(char c)
{
	int	ret;

	ret = ft_putchar_pf(c);
	if (ret == -1)
		return (-1);
	return (ret);
}

int	handle_format(const char specifier, va_list args)
{
	if (specifier == 'c')
		return (handle_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbr_unsigned_pf(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hexadecimal_lower(va_arg(args, unsigned int)));
	else if (specifier == 'X')
		return (ft_print_hexadecimal_upper(va_arg(args, unsigned int)));
	else if (specifier == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	else if (specifier == '%')
		return (handle_char('%'));
	else
		return (0);
}

int	process_char(const char **format, va_list args)
{
	int	ret;

	if (**format == '%' && *(*format + 1))
	{
		(*format)++;
		ret = handle_format(**format, args);
		if (ret == -1)
			return (-1);
	}
	else
	{
		ret = handle_char(**format);
		if (ret == -1)
			return (-1);
	}
	(*format)++;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	count = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (*format)
	{
		ret = process_char(&format, args);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		count += ret;
	}
	va_end(args);
	return (count);
}
