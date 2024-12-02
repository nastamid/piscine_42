/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:15:22 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/11 23:18:49 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}

// #include <assert.h>
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	dest[50];
// 	char	src[50];

// 	strcpy(src, "Hello, World!");
// 	ft_memmove(dest, src, strlen(src) + 1);
// 	assert(strcmp(dest, "Hello, World!") == 0);
// 	strcpy(dest, "123456789");
// 	ft_memmove(dest + 2, dest, 5);
// 	assert(strcmp(dest, "121234589") == 0);
// 	strcpy(dest, "123456789");
// 	ft_memmove(dest, dest + 2, 5);
// 	assert(strcmp(dest, "345676789") == 0);
// 	strcpy(dest, "abcdef");
// 	ft_memmove(dest, src, 0);
// 	assert(strcmp(dest, "abcdef") == 0);
// 	printf("All tests passed!\n");
// 	return (0);
// }
