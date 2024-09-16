/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 23:01:11 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/16 22:43:04 by nastamid         ###   ########.fr       */
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

static void	free_array(char **array, int i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
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
		array[i] = ft_substr(s, 0, end - start);
		if (!array[i])
		{
			free_array(array, i);
			return (NULL);
		}
		i++;
		s = end;
	}
	return (array[i] = NULL, array);
}

// #include <assert.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Function to print arrays for comparison
// void	print_split(char **result)
// {
// 	int	i;

// 	i = 0;
// 	while (result[i] != NULL)
// 	{
// 		printf("'%s', ", result[i]);
// 		i++;
// 	}
// 	printf("NULL\n");
// }

// // Function to free allocated memory
// void	free_split(char **result)
// {
// 	int	i;

// 	i = 0;
// 	while (result[i])
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// }

// // Helper function to compare two string arrays
// int	compare_split(char **result, const char **expected)
// {
// 	int	i;

// 	i = 0;
// 	while (expected[i] != NULL || result[i] != NULL)
// 	{
// 		if ((expected[i] == NULL && result[i] != NULL) || (expected[i] != NULL
// 				&& result[i] == NULL) || strcmp(result[i], expected[i]) != 0)
// 		{
// 			return (0); // Not equal
// 		}
// 		i++;
// 	}
// 	return (1); // Equal
// }

// // Test case function
// void	test_ft_split(char const *input, char delimiter, const char **expected)
// {
// 	char	**result;

// 	result = ft_split(input, delimiter);
// 	if (compare_split(result, expected))
// 	{
// 		printf("Test passed for input: '%s'\n", input);
// 	}
// 	else
// 	{
// 		printf("Test failed for input: '%s'. Expected: ", input);
// 		print_split((char **)expected);
// 		printf("Got: ");
// 		print_split(result);
// 	}
// 	free_split(result);
// }

// // Main function to run all test cases
// int	main(void)
// {
// 	const char	*expected1[] = {"hello", "world", NULL};
// 	const char	*expected2[] = {"abc", "def", "ghi", NULL};
// 	const char	*expected3[] = {"abc", "", "ghi", NULL};
// 	const char	*expected5[] = {"one", "two", "three", NULL};

// 	test_ft_split("hello world", ' ', expected1);
// 	test_ft_split("abc:def:ghi", ':', expected2);
// 	test_ft_split("abc::ghi", ':', expected3);
// 	const char *expected4[] = {NULL}; // Empty string case
// 	test_ft_split("", ' ', expected4);
// 	test_ft_split("one two three", ' ', expected5);
// 	const char *expected6[] = {NULL}; // Only delimiter
// 	test_ft_split(":::::", ':', expected6);
// 	const char *expected7[] = {NULL}; // NULL input edge case
// 	test_ft_split(NULL, ' ', expected7);
// 	return (0);
// }
