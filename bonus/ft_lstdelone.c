/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:53:16 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/08 19:18:54 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "stdlib.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
	}
}

// #include "stdio.h"

// void	test_del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;
// 	char	*s1;
// 	char	*s2;

// 	s1 = ft_strdup("Hey");
// 	s2 = ft_strdup("There");
// 	l1 = ft_lstnew(s1);
// 	l2 = ft_lstnew(s2);
// 	ft_lstadd_back(&l1, l2);
// 	printf("Before: l1 content: %s, l2 content %s\n", (char *)l1->content,
// 		(char *)l1->next->content);
// 	ft_lstdelone(l1, &test_del);
// 	printf("After: l1 content: %s, l2 content %s\n", (char *)l1->content,
// 		(char *)l1->next->content);
// 	free(l1);
// 	free(l2);
// }
