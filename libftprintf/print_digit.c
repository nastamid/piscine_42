/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:45:19 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/30 17:16:18 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

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
