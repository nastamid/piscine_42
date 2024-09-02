/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:10:39 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/24 17:46:28 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	result *= nb * ft_recursive_factorial(nb - 1);
	nb -= 1;
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_recursive_factorial(5));
// 	printf("%d\n", ft_recursive_factorial(4));
// 	printf("%d\n", ft_recursive_factorial(3));
// 	printf("%d\n", ft_recursive_factorial(0));
// 	printf("%d\n", ft_recursive_factorial(-1));
// 	printf("%d\n", ft_recursive_factorial(-5));
// }