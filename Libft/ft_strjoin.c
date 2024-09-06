/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:26:26 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/06 10:08:02 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	buffer = malloc((len1 + len2 + 1) * sizeof(char));
	if (!buffer)
		return (0);
	i = 0;
	while (i < len1 + len2)
	{
		if (i < len1)
			buffer[i] = s1[i];
		else
			buffer[i] = s2[i - len1];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	*strjoin;
// 	char	*s1;
// 	char	*s2;

// 	s1 = "Lorem Ipsum";
// 	s2 = "dolor sit amet";
// 	if (!(strjoin = ft_strjoin(s1, s2)))
// 		printf("NULL");
// 	else
// 		printf("%s\n", strjoin);
// 	if (strjoin == s1 || strjoin == s2)
// 		printf("\nA new string was not returned");
// }
