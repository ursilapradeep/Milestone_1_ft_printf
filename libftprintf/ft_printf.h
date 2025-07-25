/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:52:26 by uvadakku          #+#    #+#             */
/*   Updated: 2025/07/25 14:13:00 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putchar_pf(char c);
int	ft_putstr_pf(const char *str);
int	ft_putnbr_pf(long n);
int	ft_putnbr_unsigned_pf(unsigned int n);
int	ft_putnbr_hex(uintptr_t n, int uppercase);
int	ft_print_pointer(void *ptr);
int	ft_print_hexadecimal(unsigned int n, int uppercase);
int	ft_print_hexadecimal_lower(unsigned int n);
int	ft_print_hexadecimal_upper(unsigned int n);
int	ft_printf(const char *format, ...);
int	handle_format(const char specifier, va_list args);
int	handle_char(char c);

#endif