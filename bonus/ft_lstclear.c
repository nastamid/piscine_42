/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:21:03 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/08 19:52:40 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "stdlib.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst && !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

// #include "stdio.h"

// void	test_del(void *content)
// {
// 	if (content)
// 		free(content);
// }

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;
// 	t_list	*l3;
// 	t_list	*l4;
// 	t_list	*temp;
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;
// 	char	*s4;

// 	s1 = ft_strdup("Hey");
// 	s2 = ft_strdup("There");
// 	s3 = ft_strdup("I am ");
// 	s4 = ft_strdup("Nick");
// 	l1 = ft_lstnew(s1);
// 	l2 = ft_lstnew(s2);
// 	l3 = ft_lstnew(s3);
// 	l4 = ft_lstnew(s4);
// 	ft_lstadd_back(&l1, l2);
// 	ft_lstadd_back(&l1, l3);
// 	ft_lstadd_back(&l1, l4);
// 	temp = l1;
// 	while (temp->next)
// 	{
// 		printf("Before: Node content: %s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	printf("Before: Node content: %s\n", (char *)temp->content);
// 	ft_lstclear(&l2, &test_del);
// 	if (l2 == NULL)
// 		printf("After: List is cleared and set to NULL.\n");
// 	temp = l1;
// }
