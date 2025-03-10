/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:31:42 by codespace         #+#    #+#             */
/*   Updated: 2024/10/17 15:15:57 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static unsigned int	count_hex(unsigned int n)
{
	unsigned int	count;

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
	char			*s;
	char			hex_letter;
	unsigned int	char_count;
	unsigned int	remainder;

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
	char			*hex;
	unsigned int	char_count;

	char_count = 0;
	hex = number_to_hex(n, is_uppercase);
	if (hex)
	{
		char_count = print_string(hex);
		free(hex);
	}
	return (char_count);
}
