/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:32:59 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/02 13:50:30 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	print_pointer(void *ptr)
{
	uintptr_t	address;
	char		hex[16];
	int			i;
	int			remainder;
	int			counter;

	if (!ptr)
		return (print_string("(nil)"), 5);
	address = (uintptr_t)ptr;
	i = 0;
	counter = print_string("0x");
	remainder = 0;
	while (address)
	{
		remainder = address % 16;
		if (remainder < 10)
			hex[i] = '0' + remainder;
		else
			hex[i] = 'a' + (remainder - 10);
		i++;
		address /= 16;
	}
	while (i--)
		counter += print_char(hex[i]);
	return (counter);
}
