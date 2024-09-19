/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:32:41 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/19 13:43:06 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_size;

	if (little[0] == '\0')
		return ((char *)big);
	l_size = ft_strlen(little);
	i = 0;
	while (big[i] && i + l_size <= len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j])
			j++;
		if (j == l_size)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <assert.h>
// #include <string.h> 

// int	main(void)
// {
// 	const char	*big = "Hello World!";
// 	const char	*little = "World";
// 	const char	*big2 = "A string with a needle at the end needle";
// 	const char	*little2 = "needle";

// 	assert(ft_strnstr(big, little, 12) == strstr(big, little));
// 	assert(ft_strnstr(big, little, 5) == NULL);
// 	assert(ft_strnstr(big, "Hello", 12) == strstr(big, "Hello"));
// 	assert(ft_strnstr(big, "", 12) == strstr(big, ""));
// 	assert(ft_strnstr(big, "World", 9) == NULL);
// 	assert(ft_strnstr("abc", "abcdef", 3) == NULL);
// 	assert(ft_strnstr("", "", 1) == strstr("", ""));
// 	assert(ft_strnstr("", "abc", 0) == NULL);
// 	assert(ft_strnstr(big2, little2, strlen(big2)) == strstr(big2, little2));
// 	assert(ft_strnstr("abcd", "bcd", 3) == NULL);
// 	printf("All tests passed!\n");
// 	return (0);
// }
