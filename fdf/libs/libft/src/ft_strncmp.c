/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:57:02 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/04 14:51:52 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		++i;
	}
	if (i != n)
		return (str1[i] - str2[i]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	argc = argc + 0;
// 	(void)argv;
// 	//printf("%d\n", ft_strncmp(argv[1], argv[2], 5));
// 	//printf("%d\n", strncmp(argv[1], argv[2], 5));
// 	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
// 	return (0);
// }
