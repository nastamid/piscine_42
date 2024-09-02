/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:33:12 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/16 09:35:02 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_reverse(int *tab, int position, int size)
{
	int	n;

	if (position > 0)
	{
		n = *(tab + position - 1);
		ft_reverse(tab, --position, size);
		tab[size - position - 1] = n;
	}
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	position;

	position = size;
	ft_reverse(tab, position, size);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("Main:\n");
	int	size = 6;
	int	array[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 11;
	}
	printf("Original:\n");
	for (int i = 0; i < size; i++)
	{
		printf("Array %d: %d\n", i, array[i]);
	}
	printf("Reversed---------------\n");
	ft_rev_int_tab(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("Array %d: %d\n", i, array[i]);
	}
}
*/