/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:17:27 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/02 13:50:33 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_string(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (write(1, str, ft_strlen(str)));
}
