/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:17:27 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/01 12:31:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
