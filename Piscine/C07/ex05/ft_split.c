/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:07:04 by nastamid          #+#    #+#             */
/*   Updated: 2024/08/01 13:48:22 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Create a function that splits a string of character depending on another string of
// characters.
// • You’ll have to use each character from the string charset as a separator.
// • The function returns an array where each element of the array contains the address
// of a string wrapped between two separators. The last element of that array should
// equal to 0 to indicate the end of the array.
// • There cannot be any empty strings in your array. Get your own conclusions ac-
// cordingly.
// • The string given as argument won’t be modifiable.
// • Here’s how it should be prototyped :

char **ft_split(char *str, char *charset)
{
    
}

#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	char t1[4] = "Hey!There,Its!42";
	
	char **strs = malloc(5 * sizeof(char *));
	char *result;
	char sep[3] = "!,";


	result = ft_split(strs, sep);

	write(1, result, get_required_size(5, strs, sep));
}