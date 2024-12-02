/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:20:15 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/17 15:28:11 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	i;

	if (str == 0)
	{
		return (0);
	}
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// #include <stdio.h>
// int main (int argc, char *argv[])
// {
// 	printf("%d", ft_strlen(argv[1]));
// }
