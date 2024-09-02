/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:33:12 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/16 10:23:17 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	short	is_swap;
	int		position;

	is_swap = 1;
	while (is_swap)
	{
		position = 0;
		is_swap = 0;
		while (position + 1 < size)
		{
			if (tab[position] > tab[position + 1])
			{
				swap(&tab[position], &tab[position + 1]);
				is_swap = 1;
			}
			position++;
		}
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

void	test_swap(void)
{
	int	a;
	int	b;

	a = 5;
	b = 10;
	printf("----------Swap Test Start----------\n");
	printf("Original a: %d, b:%d\n", a, b);
	swap(&a, &b);
	printf("Swap Test:\n");
	printf("Swapped a: %d, b:%d\n", a, b);
	printf("---------Swap Test End-----------\n");
}

void	test_sort(void)
{
	int	size;
	int	array[10];

	size = sizeof(array) / sizeof(int);
	printf("---------Sort Test Start-----------\n");
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 101;
	}
	printf("Original:\n");
	for (int i = 0; i < size; i++)
	{
		printf("Array %d: %d\n", i, array[i]);
	}
	printf("---------Sorted-----------\n");
	ft_sort_int_tab(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("Array %d: %d\n", i, array[i]);
	}
	printf("---------Sort Test End-----------\n");
}

int	main(void)
{
	test_swap();
	test_sort();
}
*/
