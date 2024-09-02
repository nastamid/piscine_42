/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:27:32 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/29 13:39:33 by nastamid         ###   ########.fr       */
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

// #include <stdio.h>

// int	main(void)
// {
// 	// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
// 	printf("%d\n", ft_is_prime(-4)); // 0
// 	printf("%d\n", ft_is_prime(-1)); // 0
// 	printf("%d\n", ft_is_prime(0));  // 0
// 	printf("%d\n", ft_is_prime(1));  // 0
// 	printf("%d\n", ft_is_prime(4));  // 0
// 	printf("%d\n", ft_is_prime(16)); // 0
// 	printf("%d\n", ft_is_prime(10)); // 0
// 	printf("%d\n", ft_is_prime(2165)); // 0
// 	printf("Rest Should be 1 \n");
// 	printf("%d\n", ft_is_prime(2));  // 1
// 	printf("%d\n", ft_is_prime(3));  // 1
// 	printf("%d\n", ft_is_prime(5));  // 1
// 	printf("%d\n", ft_is_prime(7));  // 1
// 	printf("%d\n", ft_is_prime(11)); // 1
// 	printf("%d\n", ft_is_prime(13)); // 1
// 	printf("%d\n", ft_is_prime(17)); // 1
// 	printf("%d\n", ft_is_prime(19)); // 1
// }