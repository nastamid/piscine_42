/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:32:41 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/04 22:46:20 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	k;
	int	l_size;

	if (!little)
		return ((char *)big);
	l_size = ft_strlen((char *)little);
	i = 0;
	k = 0;
	while (i < (int)len)
	{
		while ((i < (int)len) && little[k] && little[k] == big[i])
		{
			k++;
			i++;
		}
		if (!little[k])
			return ((char *)&(big[i - l_size]));
		k = 0;
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s", ft_strnstr("Hey There!", "There", 10));
// }
