/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:26:26 by nastamid          #+#    #+#             */
/*   Updated: 2024/08/01 11:37:16 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_total_size_of_strings(int size, char **strs)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			j++;
			count++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	get_required_size(int size, char **strs, char *sep)
{
	int	sep_len;
	int	total_size_of_strings;
	int	required_size;

	sep_len = ft_strlen(sep);
	total_size_of_strings = get_total_size_of_strings(size, strs);
	required_size = (sizeof(char) * total_size_of_strings) + ((sep_len
				* sizeof(char) * (size - 1)));
	printf("total_size_of_strings: %d\n", total_size_of_strings);
	printf("sep_len: %d\n", sep_len);
	printf("In Total Required Size: %d\n", required_size);
	return (required_size);
}

void	concat_strings(int size, char **strs, char *sep, char *buffer)
{
	int	i;
	int	j;
	int	offset;
	int	sep_i;

	i = 0;
	j = 0;
	offset = 0;
	sep_i = 0;
	while (i < size)
	{
		while (strs[i][j])
			buffer[offset++] = strs[i][j++];
		if (i != size - 1)
		{
			while (sep[sep_i])
				buffer[offset++] = sep[sep_i++];
		}
		sep_i = 0;
		j = 0;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*buffer;
	char	*is_valid;

	is_valid = 0;
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	buffer = malloc(get_required_size(size, strs, sep));
	concat_strings(size, strs, sep, buffer);
	return (buffer);
}

// #include <unistd.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char t1[4] = "Hey";
// 	char t2[6] = "There";
// 	char t3[5] = "This";
// 	char t4[3] = "Is";
// 	char t5[3] = "42";

// 	char **strs = malloc(5 * sizeof(char *));
// 	char *result;
// 	char sep[3] = "!!";

// 	strs[0] = &t1[0];
// 	strs[1] = &t2[0];
// 	strs[2] = &t3[0];
// 	strs[3] = &t4[0];
// 	strs[4] = &t5[0];

// 	result = ft_strjoin(5, strs, sep);

// 	write(1, result, get_required_size(5, strs, sep));
// }