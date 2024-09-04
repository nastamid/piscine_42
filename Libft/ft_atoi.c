/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:21:52 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/04 15:32:48 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	whitespaces(char *str, int *ptr_i)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	*ptr_i = i;
}

int	get_sign(char *str, int *ptr_i)
{
	int	sign;
	int	i;

	sign = 0;
	i = *ptr_i;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (sign != 0)
			return (0);
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '+')
			sign = 1;
		i++;
	}
	*ptr_i = i;
	return (sign);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = 0;
	whitespaces(str, &i);
	sign = get_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (sign != 0)
		result *= sign;
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("expected: 0 result: %d ", ft_atoi("+-54"));
// 	printf("expected: 0 result: %d ", ft_atoi("-+48"));
// 	printf("expected: 0 result: %d ", ft_atoi("--48"));
// }