/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:21:07 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/29 11:56:39 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	result;

	result = 0;
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1 || index == 2)
		return (1);
	result += (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_fibonacci(0)); // 0
// 	printf("%d\n", ft_fibonacci(1)); // 1
// 	printf("%d\n", ft_fibonacci(2)); // 1
// 	printf("%d\n", ft_fibonacci(3)); // 2
// 	printf("%d\n", ft_fibonacci(4)); // 3
// 	printf("%d\n", ft_fibonacci(5)); // 5
// 	printf("%d\n", ft_fibonacci(6)); // 8
// 	printf("%d\n", ft_fibonacci(7)); // 13
// }