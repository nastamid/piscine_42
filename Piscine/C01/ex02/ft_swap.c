/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:09:47 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/15 11:09:49 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tempa;

	tempa = *a;
	*a = *b;
	*b = tempa;
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 11;
	printf("\n");
	printf("Before swap a: %d\n", a);
	printf("Before swap b: %d\n", b);
	ft_swap(&a, &b);
	printf(":-------------\n");
	printf("After swap a: %d\n", a);
	printf("After swap b: %d\n", b);
	return (0);
}
*/