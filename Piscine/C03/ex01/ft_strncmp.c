/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:57:02 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/23 11:53:40 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	argc = argc + 0;
// 	printf("%d\n", ft_strncmp(argv[1], argv[2], 5));
// 	printf("%d\n", strncmp(argv[1], argv[2], 5));
// 	return (0);
// }
