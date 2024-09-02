/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:59:51 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/29 16:00:29 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	a;
	int	max_value;

	a = 2;
	max_value = nb;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb >= a)
	{
		while (a < max_value)
		{
			if (nb == (a * a))
			{
				return (a);
			}
			a++;
		}
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(-4));          // 0
	printf("%d\n", ft_sqrt(-1));          // 0
	printf("%d\n", ft_sqrt(0));           // 0
	printf("%d\n", ft_sqrt(1));           // 0
	printf("%d\n", ft_sqrt(4));           // 2
	printf("%d\n", ft_sqrt(16));          // 4
	printf("%d\n", ft_sqrt(10));          // 0
	printf("%d\n", ft_sqrt(6250*6250));       // 6250
	printf("%d\n", ft_sqrt(6250*6250));
}*/