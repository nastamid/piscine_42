/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:45:35 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/08 18:31:40 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// #include "stdio.h"
// #include "stdlib.h"

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;
// 	t_list	**lists;
// 	int		c1;
// 	int		c2;

// 	c1 = 100;
// 	c2 = 200;
// 	l1 = ft_lstnew(&c1);
// 	l2 = ft_lstnew(&c2);
// 	lists = &l1;                
// 	ft_lstadd_front(lists, l2); 
// 	printf("l1 content: %d, next content: %d\n", *(int *)lists[0]->content,
// 		*(int *)lists[0]->next->content);
// 	free(l1);
// 	free(l2);
// }
