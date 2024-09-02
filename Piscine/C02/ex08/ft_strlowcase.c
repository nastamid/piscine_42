/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:33:30 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/17 12:35:30 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "aaazzz123";
	char	str2[] = "AaAbBbzZz";
	char	str3[] = "ASDXCZ";
	char	str4[] = "a1A23";
	char	str5[] = " ";
	char	str6[] = "~";

	printf("aaazzz123 is : %s\n", ft_strlowcase(str1));
	printf("AaAbBbzZz is : %s\n", ft_strlowcase(str2));
	printf("ASDXCZ is : %s\n", ft_strlowcase(str3));
	printf("a1A23 : %s\n", ft_strlowcase(str4));
	printf("First printable SPACE is : %s\n", ft_strlowcase(str5));
	printf("Last Printable ~ is : %s\n", ft_strlowcase(str6));
}
*/