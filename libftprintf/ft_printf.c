/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:04:10 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/28 15:24:09 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

int	print_format(char format, va_list ap)
{
	if (format == 'd')
		return (print_digit(va_arg(ap, int)));
	else if (format == 'c')
		return (print_char(va_arg(ap, int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_format(*format, ap);
		}
		else
			count += print_char(*format);
		format++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	ft_printf("int: %d \n", 52);
	ft_printf("char: %c \n", 'k');
	ft_printf("Int: %d, char: %c\n", 42, 'q');
}
