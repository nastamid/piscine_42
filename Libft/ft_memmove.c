/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:15:22 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/04 19:24:59 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*temp;
	int		i;

	s = (char *)src;
	temp = (char *)malloc(sizeof(char *) * n);
	i = 0;
	while (i < (int)n)
	{
		temp[i] = s[i];
		i++;
	}
	ft_memcpy(dest, temp, n);
	return (dest);
}
