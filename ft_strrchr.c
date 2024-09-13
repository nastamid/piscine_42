/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:30:46 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/13 13:33:45 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			last_occurrence = (char *)s;
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (last_occurrence);
}

// #include "libft.h"
// #include <stdio.h>

// void	run_test(const char *test_name, const char *str, int c,
// 		const char *expected)
// {
// 	char	*result;

// 	result = ft_strrchr(str, c);
// 	if (expected)
// 		printf("%s: %s\n", test_name, !ft_strncmp(result, expected,
// 				ft_strlen(expected)) ? result : ft_strjoin(result, " -WRONG-"));
// 	else
// 		printf("%s: %s\n", test_name, !result ? result : "(null)");
// }

// int	main(void)
// {
// 	run_test("Test 1 - Basic Test: Character Found", "hello world", 'o',
// 		"orld");
// 	run_test("Test 2 - Basic Test: Character Not Found", "hello world", 'x',
// 		NULL);
// 	run_test("Test 3 - Character is the Null Terminator", "hello world", '\0',
// 		"hello world");
// 	run_test("Test 4 - Character Appears Multiple Times", "banana", 'a', "ana");
// 	run_test("Test 5 - Empty String", "", 'a', NULL);
// 	run_test("Test 6 - Search in String of Length 1", "a", 'a', "a");
// 	// run_test("Test 7 - Non-Printable Character", "hello\0world", '\0',
// "world");
// 	run_test("Test 7 - Null String Pointer", NULL, 'a', NULL);

// 	return (0);
// }