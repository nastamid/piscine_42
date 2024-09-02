/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:44:00 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/31 19:28:36 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*result;

	len = ft_strlen(src);
	result = malloc(len * sizeof(char) + 1);
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <unistd.h>

// int	main(void)
// {
// 	write(1, ft_strdup("ABC"), 3);
// 	write(1, ft_strdup("\n"), 1);
// 	write(1, ft_strdup("ABCD"), 4);
// }