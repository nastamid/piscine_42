/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:04:10 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/30 17:58:41 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

int	print_format(char format, va_list ap)
{
	if (format == 'c')
		return (print_char(va_arg(ap, int)));
	else if (format == 's')
		return (print_string(va_arg(ap, char *)));
	else if (format == 'p')
		return (print_pointer(va_arg(ap, void *)));
	else if (format == 'd')
		return (print_char(va_arg(ap, int)));
	else if (format == 'i')
		return (print_digit(va_arg(ap, int)));
	else if (format == 'u')
		return (print_char(va_arg(ap, int)));
	else if (format == 'x')
		return (print_char(va_arg(ap, int)));
	else if (format == 'X')
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

#include <stdio.h>

int	main(void)
{
	int	k;
	int	*p;

	k = 5;
	p = &k;
	ft_printf("char: %c \n", 'C');
	ft_printf("string: %s \n", "I am ^^ && ** (( $$ %% string!");
	ft_printf("pointer %p\n", p);
	printf("Origianl_pointer %p\n", p);
	// ft_printf("decimal: %d \n", 123.12);
	printf("decimal %f", 123.12);
	// ft_printf("Int: %i, char: %c\n", 42, 'q');
}
