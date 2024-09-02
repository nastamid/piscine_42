/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:31:27 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/15 13:31:36 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b)
	{
		*div = a / b;
		*mod = a % b;
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int a = 11;
// 	int b = 5;
// 	int *div = malloc(4);
// 	int *mod = malloc(4);

// 	ft_div_mod(a, b, div, mod);
// 	printf("div: %d\n", *div);
// 	printf("mod: %d\n", *mod);

// 	return (0);
// }