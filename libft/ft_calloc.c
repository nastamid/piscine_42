/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:28:50 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/20 13:58:39 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			total_size;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 18446744073709551615UL / size)
		return (NULL);
	total_size = nmemb * size;
	p = (unsigned char *)malloc(total_size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int		*array;
// 	size_t	count;
// 	char	*str;

// 	count = 5;
// 	array = ft_calloc(count, sizeof(int));
// 	if (!array)
// 	{
// 		printf("Allocation Failed");
// 	}
// 	else
// 	{
// 		write(1, array, count);
// 		free(array);
// 	}
// 	write(1, "\n", 1);
// 	str = (char *)ft_calloc(30, 1);
// 	if (!str)
// 		write(1, "NULL", 4);
// 	else
// 		write(1, str, 30);
// 	free(str);
// }
