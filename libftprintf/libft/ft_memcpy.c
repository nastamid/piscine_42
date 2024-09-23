/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:34:42 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/11 22:50:53 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	char		*des;
	const char	*src;
	size_t		i;

	if (!destination && !source && num != 0)
		return (destination);
	des = (char *)destination;
	src = (const char *)source;
	i = 0;
	while (i < num)
	{
		des[i] = src[i];
		i++;
	}
	return (destination);
}
