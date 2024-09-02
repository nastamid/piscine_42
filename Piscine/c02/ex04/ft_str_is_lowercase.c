/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:17 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/17 12:36:14 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	is_valid_char(char c)
{
	if ((c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_lowercase(char *str)
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
	printf("ASDXCZ is : %d\n", ft_str_is_lowercase("ASDXCZ"));
	printf("asd!@#zxc is : %d\n", ft_str_is_lowercase("asd!@#zxc"));
	printf("asd1zcxz is : %d\n", ft_str_is_lowercase("asd1zcxz"));
	printf("! is : %d\n", ft_str_is_lowercase("!"));
	printf("2 is : %d\n", ft_str_is_lowercase("2"));
	printf("a is : %d\n", ft_str_is_lowercase("a"));
	printf("Emptiness is : %d\n", ft_str_is_lowercase(""));
	printf("asdxcz is : %d\n", ft_str_is_lowercase("asdxcz"));
}
*/