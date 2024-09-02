/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:31:09 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/23 11:56:17 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (j < nb && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	argc = argc + 0;
// 	//printf("%s\n", ft_strncat(argv[1], argv[2], 2));
// 	printf("%s\n", ft_strncat(argv[1], argv[2], 2));
// 	return (0);
// }