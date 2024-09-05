/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:04:17 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/05 21:51:49 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n--)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	b1[4] = {0x01, 0x02, 0x03, 0x04};
// 	char	b2[4] = {0x01, 0x02, 0x03, 0x01};

// 	printf("%d", ft_memcmp(b1, b2, 4));
// }
