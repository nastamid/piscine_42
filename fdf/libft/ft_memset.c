/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:09:54 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/02 16:32:56 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	uc;
	int				i;
	char			*str;

	i = 0;
	uc = (unsigned char)c;
	str = (char *)s;
	while (i < n)
	{
		str[i] = uc;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[50];
	int		arr[10];
	char	str1[20];

	strcpy(str, "ABCD QWERTY");
	puts(str);
	ft_memset(str, '@', 5);
	puts(str);
	ft_memset(arr, 0, sizeof(arr));
	printf("Array after memset(): ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	ft_memset(str1, 'Z', 10);
	printf("String after memset(): %s\n", str1);
	return (0);
}
*/