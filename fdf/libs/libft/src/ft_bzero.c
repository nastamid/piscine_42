/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:29:50 by nastamid          #+#    #+#             */
/*   Updated: 2024/11/18 20:41:13 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[15];

	strcpy(str, "ABCD QWERTY");
	puts(str);
	ft_bzero(str, 5);
	puts(str); // Doesn't show because it fills with end of lines
	return (0);
}

*/