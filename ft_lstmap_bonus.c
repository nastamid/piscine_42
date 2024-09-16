/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:27:02 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/16 22:37:34 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stddef.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;
	void	*new_content;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_elem = ft_lstnew(new_content);
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

// #include <stdio.h>
// #include <stdlib.h>

// void	*set_42(void *content)
// {
// 	char	*new_str;

// 	(void)content;
// 	new_str = ft_strdup("42");
// 	return (new_str);
// }

// void	free_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*original_list;
// 	t_list	*new_list;
// 	t_list	*temp;
// 	char	*s1;
// 	char	*s2;
// 	char	*s3;
// 	char	*s4;

// 	s1 = ft_strdup("Hello");
// 	s2 = ft_strdup("World");
// 	s3 = ft_strdup("From");
// 	s4 = ft_strdup("ft_lstmap");
// 	// Create the original list
// 	original_list = ft_lstnew(s1);
// 	ft_lstadd_back(&original_list, ft_lstnew(s2));
// 	ft_lstadd_back(&original_list, ft_lstnew(s3));
// 	ft_lstadd_back(&original_list, ft_lstnew(s4));
// 	// Display original list
// 	printf("Original list:\n");
// 	temp = original_list;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	printf("\nNew list (after mapping):\n");

// 	new_list = ft_lstmap(original_list, set_42, free_content);
// 	// Display new list
// 	temp = new_list;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	// Clean up both lists
// 	ft_lstclear(&original_list, free_content);
// 	ft_lstclear(&new_list, free_content);
// 	return (0);
// }
