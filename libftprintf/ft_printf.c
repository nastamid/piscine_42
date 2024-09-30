/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:04:10 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/30 21:13:28 by nastamid         ###   ########.fr       */
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

	va_start(args, format);            // Initialize the va_list
	result = vft_printf(format, args); // Call vft_printf with va_list
	va_end(args);                      // Clean up the va_list
	return (result);
}
