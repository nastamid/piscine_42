/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:45:04 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/11 23:00:06 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

// #include <unistd.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;
// 	char	*s4;
// 	char	*s5;
// 	char	str[] = "lorem ipsum dolor sit amet";

// 	s1 = "Hello There! ONCE AGAIN";
// 	s2 = ft_substr(s1, 2, 5);
// 	write(1, s2, 5);
// 	write(1, "\n", 1);
// 	s3 = ft_substr(s1, 0, 5);
// 	write(1, s3, 5);
// 	write(1, "\n", 1);
// 	s4 = ft_substr(s1, 7, 10);
// 	write(1, s4, 3);
// 	write(1, "\n", 1);
// 	s5 = ft_substr(str, 0, 10);
// 	write(1, s5, 10);
// 	write(1, "\n", 1);
// }
