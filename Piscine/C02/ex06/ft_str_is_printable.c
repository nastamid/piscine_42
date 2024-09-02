/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:48:17 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/16 17:12:46 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short	is_valid_char(char c)
{
	if ((c >= 32 && c <= 126))
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_printable(char *str)
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
	char	del;
	char	*pdell;

	printf("asd!@#zxc is : %d\n", ft_str_is_printable("asd!@#zxc"));
	printf("asd1zcxz is : %d\n", ft_str_is_printable("asd1zcxz"));
	printf("! is : %d\n", ft_str_is_printable("!"));
	printf("2 is : %d\n", ft_str_is_printable("2"));
	printf("a is : %d\n", ft_str_is_printable("a"));
	printf("asdxcz is : %d\n", ft_str_is_printable("asdxcz"));
	printf("ASDXCZ is : %d\n", ft_str_is_printable("ASDXCZ"));
	printf("Emptiness is : %d\n", ft_str_is_printable(""));
	printf("First printable SPACE is : %d\n", ft_str_is_printable(" "));
	printf("Last Printable ~ is : %d\n", ft_str_is_printable("~"));
	del = (char)127;
	pdell = &del;
	printf("Non printable DEL is : %d\n", ft_str_is_printable(pdell));
}
*/