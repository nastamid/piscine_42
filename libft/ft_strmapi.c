/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:32:20 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/08 12:15:13 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}

// char	tolower_test(unsigned int i, char c)
// {
// 	if (i % 2)
// 		return (ft_tolower(c));
// 	return (c);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*result;

// 	s1 = "ABCDEG";
// 	result = ft_strmapi(s1, tolower_test);
// 	printf("%s\n", result);
//     free (result);
// }
