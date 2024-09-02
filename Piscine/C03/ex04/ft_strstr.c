/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:31:25 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/25 15:05:03 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == 0)
		return (str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && str[i + j])
			j++;
		if (!to_find[j])
			return (str + i);
		j = 0;
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	argc = argc + 0;
	printf("%s\n", ft_strstr(argv[1], argv[2]));
	printf("%s\n", strstr(argv[1], argv[2]));
	return (0);
}