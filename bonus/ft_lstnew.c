/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:29:07 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/08 17:40:46 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->content = content;
	l->next = NULL;
	return (l);
}

// #include "stdio.h"

// int	main(void)
// {
// 	int		content;
// 	t_list	*l;

// 	content = 100;
// 	l = ft_lstnew(&content);
// 	printf("Content: %d\n", *(int *)(l->content));
// }
