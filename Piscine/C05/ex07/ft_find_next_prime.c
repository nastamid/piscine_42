/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:40:42 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/29 14:11:34 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 0 || nb == 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	max_value;

	i = nb;
	max_value = nb * 2;
	if (nb <= 2)
		return (2);
	while (i <= max_value)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
// 	printf("%d\n", ft_find_next_prime(-4));   // 0
// 	printf("%d\n", ft_find_next_prime(-1));   // 0
// 	printf("%d\n", ft_find_next_prime(0));    // 0
// 	printf("%d\n", ft_find_next_prime(1));    // 2
// 	printf("%d\n", ft_find_next_prime(4));    // 5
// 	printf("%d\n", ft_find_next_prime(16));   // 17
// 	printf("%d\n", ft_find_next_prime(10));   // 11
// 	printf("%d\n", ft_find_next_prime(2165)); // 2179
// 	printf("Rest Should be same \n");
// 	printf("%d\n", ft_find_next_prime(2));  // 1
// 	printf("%d\n", ft_find_next_prime(3));  // 1
// 	printf("%d\n", ft_find_next_prime(5));  // 1
// 	printf("%d\n", ft_find_next_prime(7));  // 1
// 	printf("%d\n", ft_find_next_prime(11)); // 1
// 	printf("%d\n", ft_find_next_prime(13)); // 1
// 	printf("%d\n", ft_find_next_prime(17)); // 1
// 	printf("%d\n", ft_find_next_prime(19)); // 1
// 	printf("%d\n", ft_find_next_prime(19)); // 1
// }