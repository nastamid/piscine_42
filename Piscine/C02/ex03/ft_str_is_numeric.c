/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:35:03 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/16 16:10:07 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	is_valid_char(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_numeric(char *str)
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
	printf("ASDXCZ is numeric: %d\n", ft_str_is_numeric("ASDXCZ"));
	printf("asdxcz is numeric: %d\n", ft_str_is_numeric("asdxcz"));
	printf("asd1zcxz is numeric: %d\n", ft_str_is_numeric("asd1zcxz"));
	printf("asd!@#zxc is numeric: %d\n", ft_str_is_numeric("asd!@#zxc"));
	printf("Emptiness is numeric: %d\n", ft_str_is_numeric(""));
	printf("a is numeric: %d\n", ft_str_is_numeric("a"));
	printf("! is numeric: %d\n", ft_str_is_numeric("!"));
	printf("2326a is numeric: %d\n", ft_str_is_numeric("2326a"));
	printf("2326a65 is numeric: %d\n", ft_str_is_numeric("2326a65"));
	printf("23@@ is numeric: %d\n", ft_str_is_numeric("23@@"));
	printf("a23@@ is numeric: %d\n", ft_str_is_numeric("a23@@"));
	printf("2326 is numeric: %d\n", ft_str_is_numeric("2326"));
	printf("2 is numeric: %d\n", ft_str_is_numeric("2"));
	printf("1234567890 is numeric: %d\n", ft_str_is_numeric("1234567890"));
}
*/