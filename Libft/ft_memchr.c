/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:52:36 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/05 22:14:13 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
	{
		if (*s1 == (unsigned char)c)
			return (s1);
		s1++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	b1[5] = {0x01, 0x0A, 0x03, 0x04, 0};
// 	int		c;
// 	char	*result;

// 	c = 3;
// 	result = ft_memchr(b1, c, 4);
// 	if (result)
// 	{
// 		printf("\n Expecting: 2 | %ld\n", result - b1);
// 	}
// 	else
// 	{
// 		printf("\n Character not found.\n");
// 	}
// }
