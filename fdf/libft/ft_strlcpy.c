/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:52:33 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/11 23:07:47 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// void	ft_print_result(int n)
// {
// 	char	c;

// 	if (n >= 10)
// 		ft_print_result(n / 10);
// 	c = n % 10 + '0';
// 	write(1, &c, 1);
// }

// int	main(void)
// {
// 	char *dest;

// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	memset(dest, 0, 15);
// 	write(1, "\n", 1);
// 	write(1, "test 1", 7);
// 	write(1, "\n", 1);
// 	ft_print_result(ft_strlcpy(dest, "lorem", 15));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 	write(1, "\n", 1);
// 	write(1, "test 2", 7);
// 	write(1, "\n", 1);
// 	ft_print_result(ft_strlcpy(dest, "", 15));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 	write(1, "\n", 1);
// 	write(1, "test 3", 7);
// 	write(1, "\n", 1);
// 	ft_print_result(ft_strlcpy(dest, "lorem ipsum", 3));
// 	write(1, "\n", 1);
// 	write(1, dest, 7);
// 	write(1, "\n", 1);
// 	write(1, "test 4", 7);
// 	write(1, "\n", 1);
// 	ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);

// 	write(1, "\n", 1);
// 	write(1, "test 5", 7);
// 	write(1, "\n", 1);
// 	ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);

// 	return (0);
// }