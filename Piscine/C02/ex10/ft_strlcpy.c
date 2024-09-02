/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:52:33 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/19 20:50:59 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				k;

	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= size - 1)
	{
		dest[i] = '\0';
		i++;
	}
	k = 0;
	while (src[k])
	{
		k++;
	}
	return (k);
}
/*
#include <stdio.h>
#include <string.h>


int	main(void)
{
	char buff[10] = "";
	char src1[6] = "ABCDE" ;
	char src2[12] = "123456789AB" ;

	int size1 = ft_strlcpy(buff, src1, sizeof(buff));
	printf("Buff1: %s\n", buff);
	printf("Size of src1: %ld\n", sizeof(src1));
	printf("Length %d\n", size1);


	int size2 = ft_strlcpy(buff, src2, sizeof(buff));
	printf("Size of src2: %ld\n", sizeof(src2));
	printf("Buff2: %s\n", buff);
	printf("Length %d\n", size2);
}*/