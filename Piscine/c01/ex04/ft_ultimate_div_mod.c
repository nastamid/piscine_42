/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:50:21 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/15 14:50:24 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	if (*b)
	{
		temp = *a;
		*a = temp / *b;
		*b = temp % *b;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int k = 15;
	int p = 4;

	int *a = &k;
	int *b = &p;

	ft_ultimate_div_mod(a, b);
	printf("div: %d\n", *a);
	printf("mod: %d\n", *b);
	return (0);
}*/