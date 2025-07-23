/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:28:35 by uvadakku          #+#    #+#             */
/*   Updated: 2025/07/22 12:01:49 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_printf(const char *format, ...)
{
	__va_list_tag args;
	va_start(args, format);
	int count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_args(args, int);
				count += ft_putchar_pf(c);
			}
		}
	}
	
}
