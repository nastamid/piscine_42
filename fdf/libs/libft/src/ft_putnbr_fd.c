/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:37:51 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/08 12:54:16 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*s;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	s = ft_itoa(n);
	if (s)
	{
		write(fd, s, ft_strlen(s));
		free(s);
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(-2147483648LL, 2);
// }
