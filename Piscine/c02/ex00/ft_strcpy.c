/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:35:45 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/16 14:38:56 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	p;

	p = 0;
	while (src[p])
	{
		dest[p] = src[p];
		p++;
	}
	dest[p] = '\0';
	return (dest);
}

/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	src[] = "hello";
	char	dest[] = "aaaaa";
	char	new[] = "";

	write(1, src, 6);
	printf("\n");
	write(1, dest, 6);
	printf("\n");
	ft_strcpy(dest, src);
	printf("\n");
	write(1, src, 6);
	printf("\n");
	write(1, dest, 6);
}
*/