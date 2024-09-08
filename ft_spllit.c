/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spllit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:01:11 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/07 11:31:17 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s++)
	{
		if (*(s - 1) != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*(s - 1) == c)
			in_word = 0;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*start;
	char	*end;
	int		i;
	int		count;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	array = ft_calloc(count + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (i < count)
	{
		while (*s == c)
			s++;
		start = (char *)s;
		end = ft_strchr(start, c);
		if (!end)
			end = start + ft_strlen(start);
		array[i++] = ft_substr(s, 0, end - start);
		s = end;
	}
	return (array[i] = NULL, array);
}

// #include <stdio.h>

// void	test(char *str, char delimiter)
// {
// 	int		count;
// 	char	**array;
// 	int		i;

// 	count = count_words(str, delimiter);
// 	array = ft_split(str, delimiter);
// 	i = 0;
// 	while (i < count)
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// 	if (count == 0)
// 	{
// 		printf("%s\n", array[0]);
// 	}
// }

// int	main(void)
// {
// 	// char	str[] = "Hello        There       I am here!    ";
// 	// test(str, ' ');
// 	test("hi kaka ", ' ');
// 	test("Hello        There       I am here!    ", ' ');
// 	test("XXX", ' ');
// 	test("", 'k');
// }
