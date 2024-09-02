/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:22:36 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/23 15:22:20 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkerror(char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (str[0] == '\0' || len == 1)
		return (0);
	while (str[i])
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		error;
	long	nb;

	error = checkerror(base);
	len = ft_strlen(base);
	nb = nbr;
	if (error == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb < len)
			ft_putchar(base[nb]);
		if (nb >= len)
		{
			ft_putnbr_base(nb / len, base);
			ft_putnbr_base(nb % len, base);
		}
	}
}

// int main (void)
// {
// 	ft_putnbr_base(42, "0123456789");
// 	ft_putchar(*"\n");
// 	ft_putnbr_base(42, "0123456789ABCDEF");
// 	ft_putchar(*"\n");
// 	ft_putnbr_base(42, "poneyvif");
// 	ft_putchar(*"\n");
// 	ft_putnbr_base(-2147483648, "0123456789");
// 	ft_putchar(*"\n");
// 	ft_putnbr_base(2147483647, "0123456789");
// 	ft_putchar(*"\n");
// 	ft_putnbr_base(123456789, "0123456789ABCDEF");
// 	ft_putchar(*"\n");
// 	ft_putnbr_base(123456789, "poneyvif");
// }
