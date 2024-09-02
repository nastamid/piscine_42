/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:40:29 by nastamid          #+#    #+#             */
/*   Updated: 2024/08/01 12:06:42 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Create a function that returns the result of the conversion of the string nbr from a
// base base_from to a base base_to.
// • nbr, base_from, base_to may be not writable.
// • nbr will follow the same rules as ft_atoi_base (from an other module). Beware of
// ’+’, ’-’ and whitespaces.
// • The number represented by nbr must fit inside an int.
// • If a base is wrong, NULL should be returned.
// • The returned number must be prefix only by a single and uniq ’-’ if necessary,

// whitespaces, no ’+’.
// • Here’s how it should be prototyped :

#include <unistd.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{

	char	*k;

	k = malloc(2);
	k[0] = 'a';
	k[1] = '\0';
	return (k);
}

void	ft_putchar(char *c)
{
	write(1, c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(str++);
}

int	main(void)
{
	ft_putstr(ft_convert_base("465", "0123456789", "01")); // 111010001
}