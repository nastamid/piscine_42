/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:04:10 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/01 15:07:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	print_format(char format, va_list ap)
{
	if (format == 'c')
		return (print_char(va_arg(ap, int)));
	else if (format == 's')
		return (print_string(va_arg(ap, char *)));
	else if (format == 'p')
		return (print_pointer(va_arg(ap, void *)));
	else if (format == 'd')
		return (print_digit(va_arg(ap, int)));
	else if (format == 'i')
		return (print_digit(va_arg(ap, int)));
	else if (format == 'u')
		return (print_udigit(va_arg(ap, unsigned int)));
	else if (format == 'x')
		return (print_hex(va_arg(ap, long), false));
	else if (format == 'X')
		return (print_hex(va_arg(ap, long), true));
	else
		return (print_char(format));
}

int	vft_printf(const char *format, va_list args)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += print_format(*format, args);
		}
		else
			count += print_char(*format);
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = vft_printf(format, args);
	va_end(args);
	return (result);
}

/* #include <stdio.h>

int	main(void)
{
	
	int				int_test;


	int_test = 155;

	printf("%% %c %s %d %i %u %x %X %p %%\n", 'A', "Hello", 255, 255, 255, 255,
		255, &int_test);
	ft_printf("%% %c %s %d %i %u %x %X %p %%\n", 'A', "Hello", 255, 255, 255,
		255, 255, &int_test);
} */
