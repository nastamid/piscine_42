/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:10:16 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/29 11:57:36 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (power < 0)
		return (0);
	result *= ft_recursive_power(nb, power - 1);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_recursive_power(2, 2));
// 	printf("%d\n", ft_recursive_power(3, 2));
// 	printf("%d\n", ft_recursive_power(5, 2));
// 	printf("%d\n", ft_recursive_power(5, 3));
// 	printf("3 3: %d\n", ft_recursive_power(3, 3));
// 	printf("0 20: %d\n", ft_recursive_power(0, 20));
// 	printf("1 0: %d\n", ft_recursive_power(1, 0));
// 	printf("0 0: %d\n", ft_recursive_power(0, 0));
// 	printf("4 -4: %d\n", ft_recursive_power(4, -4));
// 	printf("-2 -2: %d\n", ft_recursive_power(-2, -2));
// 	printf("-2 2: %d\n", ft_recursive_power(-2, 2));
// 	printf("-2 3: %d\n", ft_recursive_power(-2, 3));
// }