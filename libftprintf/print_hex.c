/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:31:42 by codespace         #+#    #+#             */
/*   Updated: 2024/10/01 13:23:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static long	ft_abs(long x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	count_hex(long n)
{
	int	count;

	count = 1;
	while (n / 16)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static char	*number_to_hex(long number, bool is_uppercase)
{
	char	*s;
	int		char_count;
	int		remainder;
	char	hex_letter;

	hex_letter = 'a';
	if (is_uppercase)
		hex_letter = 'A';
	remainder = 0;
	char_count = count_hex(number);
	s = (char *)malloc((char_count + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[char_count] = '\0';
	while (char_count > 0)
	{
		remainder = ft_abs(number % 16);
		if (remainder < 10)
			s[--char_count] = remainder + '0';
		else
			s[--char_count] = remainder + hex_letter - 10;
		number /= 16;
	}
	return (s);
}

int	print_hex(long n, bool is_uppercase)
{
	char	*hex;

	hex = number_to_hex(n, is_uppercase);
	print_string(hex);
	return (ft_strlen(hex));
}
