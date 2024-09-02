/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:56:57 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/23 11:22:54 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int	main(int argc, char **argv)
// {
// 	argc = argc + 0;
// 	printf("%d\n", ft_strcmp(argv[1], argv[2]));
// 	printf("%d\n", strcmp(argv[1], argv[2]));
// return (0);
// }
