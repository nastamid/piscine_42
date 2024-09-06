/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:57:26 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/06 16:23:03 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	is_trimmable(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		len;
	int		start;
	int		end;

	len = ft_strlen((char *)s1);
	start = 0;
	end = len;
	i = 1;
	while (i < len / 2)
	{
		if (is_trimmable(s1[i - 1], set))
			start = i;
		if (is_trimmable(s1[len - i], set))
			end = len - i;
		i++;
	}
	res = ft_substr(s1, start, end - start);
	return (res);
}

// #include <unistd.h>

// int	main(void)
// {
// 	char *s1 = "0123456789";

// 	char *s2 = ft_strtrim(s1, "01958");

// 	write(1, s2, 11);
// }