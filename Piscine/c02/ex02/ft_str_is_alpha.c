/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:17 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/16 15:14:22 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	is_valid_char(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	if (str[0] == '\0')
	{
		return (1);
	}
	i = 0;
	while (str[i])
	{
		if (!is_valid_char(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("ASDXCZ is alphabetic: %d\n", ft_str_is_alpha("ASDXCZ"));
	printf("asdxcz is alphabetic: %d\n", ft_str_is_alpha("asdxcz"));
	printf("asd1zcxz is alphabetic: %d\n", ft_str_is_alpha("asd1zcxz"));
	printf("asd!@#zxc is alphabetic: %d\n", ft_str_is_alpha("asd!@#zxc"));
	printf("Emptiness is alphabetic: %d\n", ft_str_is_alpha(""));
	printf("a is alphabetic: %d\n", ft_str_is_alpha("a"));
	printf("! is alphabetic: %d\n", ft_str_is_alpha("!"));
	printf("2 is alphabetic: %d\n", ft_str_is_alpha("2"));
}
*/