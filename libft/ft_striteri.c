/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:16:37 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/08 12:26:30 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*p;

	p = s;
	if (!s || !f)
		return ;
	while (*s)
	{
		f((s - p), s);
		s++;
	}
}

// void	tolower_test(unsigned int i, char *c)
// {
// 	if (i % 2)
// 		*c = ft_tolower(*c);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "ABCDEG";

// 	ft_striteri(s1, tolower_test);
// 	printf("%s\n", s1);
// }
