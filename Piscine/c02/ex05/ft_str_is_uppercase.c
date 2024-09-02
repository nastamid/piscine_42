/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:17 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/17 12:36:21 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	is_valid_char(char c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_uppercase(char *str)
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
	printf("asd!@#zxc is : %d\n", ft_str_is_uppercase("asd!@#zxc"));
	printf("asd1zcxz is : %d\n", ft_str_is_uppercase("asd1zcxz"));
	printf("! is : %d\n", ft_str_is_uppercase("!"));
	printf("2 is : %d\n", ft_str_is_uppercase("2"));
	printf("a is : %d\n", ft_str_is_uppercase("a"));
	printf("asdxcz is : %d\n", ft_str_is_uppercase("asdxcz"));
	printf("ASDXCZ is : %d\n", ft_str_is_uppercase("ASDXCZ"));
	printf("Emptiness is : %d\n", ft_str_is_uppercase(""));
}
*/