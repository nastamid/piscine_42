/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:49:23 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/31 20:28:38 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	bound;
	int	index;
	int	*buffer;
	int	*is_allocated;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	bound = max - min;
	is_allocated = (buffer = malloc(bound * sizeof(int)));
	if (!is_allocated)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	index = 0;
	while (index < bound)
	{
		buffer[index] = min + index;
		index++;
	}
	return (bound);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	*range;
// 	int	size;
// 	int	i;

// 	i = 0;
// 	size = ft_ultimate_range(&range, 5, 10);
// 	while (i < size)
// 	{
// 		printf("%d, ", range[i]);
// 		i++;
// 	}
// }
