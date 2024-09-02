/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:03:39 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/17 12:29:40 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char str1[] = "aaazzz123";
	char str2[] = "AaAbBbzZz";
	char str3[] = "ASDXCZ";
	char str4[] = "a1A23";
	char str5[] = " ";
	char str6[] = "~";
	printf("aaazzz123 is : %s\n", ft_strupcase(str1));
	printf("AaAbBbzZz is : %s\n", ft_strupcase(str2));
	printf("ASDXCZ is : %s\n", ft_strupcase(str3));
	printf("a1A23 : %s\n", ft_strupcase(str4));
	printf("First printable SPACE is : %s\n", ft_strupcase(str5));
	printf("Last Printable ~ is : %s\n", ft_strupcase(str6));
}*/