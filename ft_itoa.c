/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:33:12 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/07 22:41:16 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	count_digits(int n)
{
	int	char_count;

	char_count = 1;
	while (n / 10)
	{
		char_count++;
		n /= 10;
	}
	return (char_count);
}

char	*handle_min_int(void)
{
	char	*s;

	s = malloc(12 * sizeof(char));
	if (!s)
		return (0);
	s = "-2147483648";
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		is_negative;
	int		char_count;
	int		number;

	if (n == 1 << 31)
		return (handle_min_int());
	is_negative = (n < 0);
	number = abs(n);
	char_count = count_digits(number) + is_negative;
	s = malloc((char_count + 1) * sizeof(char));
	if (!s)
		return (0);
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
