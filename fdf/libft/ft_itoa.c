/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:33:12 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/20 17:08:27 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_digits(int n)
{
	int	count;

	count = 1;
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				is_negative;
	int				char_count;
	unsigned int	number;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = (n < 0);
	number = n;
	if (is_negative)
		number = -n;
	char_count = count_digits(number) + is_negative;
	s = malloc((char_count + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[char_count] = '\0';
	while (char_count > 0)
	{
		s[--char_count] = (number % 10) + '0';
		number /= 10;
	}
	if (is_negative)
		s[0] = '-';
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(26654));
// 	printf("%s\n", ft_itoa(2147483647));
// 	printf("%s\n", ft_itoa(-2147483648));
// 	printf("%s\n", ft_itoa(-2147483647));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-5));
// 	printf("%s\n", ft_itoa(-6514520));
// }
