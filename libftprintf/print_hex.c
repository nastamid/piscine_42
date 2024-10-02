/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:31:42 by codespace         #+#    #+#             */
/*   Updated: 2024/10/02 13:16:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	count_hex(unsigned int n)
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

static char	*number_to_hex(unsigned int number, bool is_uppercase)
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
		remainder = number % 16;
		if (remainder < 10)
			s[--char_count] = remainder + '0';
		else
			s[--char_count] = remainder + hex_letter - 10;
		number /= 16;
	}
	return (s);
}

int	print_hex(unsigned int n, bool is_uppercase)
{
	char	*hex;
	int		char_count;

	char_count = 0;
	hex = number_to_hex(n, is_uppercase);
	if (hex)
	{
		char_count = print_string(hex);
	}
	return (char_count);
}
