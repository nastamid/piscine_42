/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:29:15 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/31 19:48:51 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	range;
	int	i;

	if (min >= max)
		return (NULL);
	range = max - min;
	res = malloc(range * sizeof(int));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < range)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}

// #include <stdio.h>

// void	print_result(int *result)
// {
// 	int	i;

// 	i = 0;
//     printf("\n");
// 	while (result[i])
// 		printf("%d ", result[i++]);
// }

// int	main(void)
// {
// 	print_result(ft_range(5, 10));
//     //print_result(ft_range(10, 5));
//     // print_result(ft_range(-5, 5));
//     print_result(ft_range(-5, 0));
// }