/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:30:46 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/04 20:06:53 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*result;

	result = '\0';
	while (*s)
	{
		if (*s == (char)c)
			result = s;
		s++;
	}
	if (c != 0)
		return ((char *)result);
	else
		return ((char *)s);
	return (0);
}
