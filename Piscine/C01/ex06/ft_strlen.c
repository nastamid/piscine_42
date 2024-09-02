/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:43:26 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/15 16:43:28 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*(str + size))
	{
		size++;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Count: %d", ft_strlen("asda"));
}
*/