/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:40:01 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/19 20:50:04 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	src[] = "hello";
	char	dest[] = "aaaaa999999999";

	write(1, src, 6);
	printf("\n");
	write(1, dest, 6);
	printf("\n");
	ft_strncpy(dest, src, 4);
	printf("\n");
	write(1, src, 6);
	printf("\n");
	write(1, dest, 6);
}
*/