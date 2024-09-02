/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:29:00 by nastamid          #+#    #+#             */
/*   Updated: 2024/07/11 18:31:09 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '0';
	c = '0';

	while (a<='9')
	{
		while (b<='9')
		{
			while (c<='9')
			{
				if (a< b)
				{
					ft_putchar(a);
					if (b < c)
					{
						ft_putchar(b);
					}

					ft_putchar(c);
					ft_putchar(',');
					ft_putchar(' ');
				}

				c++;
			}
			c='0';
			b++;
		}
		b='0';
		a++;
	}
}

int	main (void)
{
	ft_print_comb();
	return (0);
}
