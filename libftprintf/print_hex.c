/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:31:42 by codespace         #+#    #+#             */
/*   Updated: 2024/10/01 10:59:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	count_hex(int n)
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

static char	*int_to_hex(int n, bool is_uppercase)
{
	char			*s;
	int				is_negative;
	int				char_count;
	unsigned int	number;
	int				remainder;
	char			hex_letter;

	hex_letter = 'a';
	if (is_uppercase)
		hex_letter = 'A';
	remainder = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = (n < 0);
	number = n;
	if (is_negative)
		number = -n;
	char_count = count_hex(number) + is_negative;
	s = malloc((char_count + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[char_count] = '\0';
	while (char_count > 0)
	{
		remainder = (number % 16);
		if (remainder < 10)
			s[--char_count] = remainder + '0';
		else
			s[--char_count] = remainder + hex_letter - 10;
		number /= 16;
	}
	if (is_negative)
		s[0] = '-';
	return (s);
}

int	print_hex(int n, bool is_uppercase)
{
	char	*hex;

	hex = int_to_hex(n, is_uppercase);
	print_string(hex);
	return (ft_strlen(hex));
}
