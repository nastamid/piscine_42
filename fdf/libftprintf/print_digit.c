/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:45:19 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/02 13:50:22 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	count_digits(long n)
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

char	*ft_uitoa(unsigned int n)
{
	char	*s;
	int		char_count;
	long	number;

	number = (long)n;
	char_count = count_digits(number);
	s = malloc((char_count + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[char_count] = '\0';
	while (char_count > 0)
	{
		s[--char_count] = (number % 10) + '0';
		number /= 10;
	}
	return (s);
}

int	print_digit(int digit)
{
	char	*s;
	int		count;

	count = 0;
	if (digit == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	s = ft_itoa(digit);
	if (s)
	{
		count = write(1, s, ft_strlen(s));
		free(s);
		return (count);
	}
	return (0);
}

int	print_udigit(unsigned int digit)
{
	char	*s;
	int		count;

	count = 0;
	s = ft_uitoa(digit);
	if (s)
	{
		count = write(1, s, ft_strlen(s));
		free(s);
		return (count);
	}
	return (0);
}
