/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:43:23 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/19 20:27:39 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	capitalize(char *c)
{
	*c -= 32;
}

int	is_capitalizer(char *c)
{
	int	is_numeric_char;
	int	is_alphabetic_char;
	int	is_normal_char;

	is_numeric_char = *c >= '0' && *c <= '9';
	is_alphabetic_char = (*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z');
	is_normal_char = is_numeric_char || is_alphabetic_char;
	return (!is_normal_char);
}

int	is_lower_char(char *c)
{
	return (*c >= 'a' && *c <= 'z');
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (is_lower_char(&str[0]))
	{
		capitalize(&str[0]);
	}
	i = 1;
	while (str[i])
	{
		if (is_capitalizer(&str[i - 1]) && is_lower_char(&str[i]))
		{
			capitalize(&str[i]);
		}
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "salut, comment tu vas";
	char	str2[] = "? 42mots quarante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(str1));
	printf("%s\n", ft_strcapitalize(str2));
}
*/