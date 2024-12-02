/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:57:26 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/20 17:53:35 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_trimmable(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_trimmable(s1[start], set))
		start++;
	while (end > start && is_trimmable(s1[end], set))
		end--;
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}

// #include <unistd.h>

// int	main(void)
// {
// 	char s1[] = " Hello There I am Here! ";
// 	char s2[] = "lorem \n ipsum \t dolor \n sit \t amet";
// 	char s3[] = " T ";
// 	char s4[] = " TX ";
// 	char s5[] = "12321";

// 	char *res1 = ft_strtrim(s1, " teH");
// 	write(1, res1, ft_strlen(res1));
// 	write(1, "\n", 1);

// 	char *res2 = ft_strtrim(s2, " te");
// 	write(1, res2, ft_strlen(res2));
// 	write(1, "\n", 1);

// 	char *res3 = ft_strtrim(s3, " ");
// 	write(1, res3, ft_strlen(res3));
// 	write(1, "\n", 1);

// 	char *res4 = ft_strtrim(s4, " X");
// 	write(1, res4, ft_strlen(res4));
// 	write(1, "\n", 1);

// 	char *res5 = ft_strtrim(s5, "123");
// 	write(1, res5, ft_strlen(res5));
// 	write(1, "\n", 1);
// }