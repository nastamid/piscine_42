/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:34:42 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/04 19:11:45 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	char	*des;
	char	*src;
	int		i;

	des = (char *)destination;
	src = (char *)source;
	i = 0;
	while (i < (int)num)
	{
		des[i] = src[i];
		i++;
	}
	return (destination);
}
