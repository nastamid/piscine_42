/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:35:13 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/16 13:44:59 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*get_next_line(int fd)
{
	FILE	*f;
	char	c;

	f = fopen("test.txt", "r");
	c = getc(f);
	while (c != EOF)
	{
		putchar(c);
		c = getc(f);
	}
	return (0);
}

int	main(void)
{
	get_next_line(1);
}
