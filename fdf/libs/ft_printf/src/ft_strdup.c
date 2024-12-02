/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:15:42 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/02 13:50:04 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	unsigned char	*p;
	size_t			len;
	size_t			i;

	len = ft_strlen((char *)s);
	p = malloc((len + 1) * sizeof(char));
	if (p)
	{
		i = 0;
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
		return ((char *)p);
	}
	else
		return (0);
}

// #include <unistd.h>

// int	main(void)
// {
// 	const char	*str = "Hello";
// 	char		*result;

// 	result = ft_strdup(str);
// 	write(1, result, ft_strlen((char *)str));
// }
