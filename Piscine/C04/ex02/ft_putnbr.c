/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:21:27 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/23 14:57:49 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

// int main (void)
// {
// 	ft_putnbr(42);
// 	ft_putchar(*"\n");
// 	ft_putnbr(-2147483648);
// 	ft_putchar(*"\n");
// 	ft_putnbr(2147483647);
// 	ft_putchar(*"\n");
// 	ft_putnbr(0);
// 	ft_putchar(*"\n");
// 	ft_putnbr(1);
//     ft_putchar(*"\n");
// 	// ft_putnbr(2147483648);
// }
