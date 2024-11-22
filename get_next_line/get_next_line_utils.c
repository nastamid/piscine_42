/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:35:16 by nastamid          #+#    #+#             */
/*   Updated: 2024/11/22 18:06:22 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	contains_newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	copy_content(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return (0);
	k = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return (1);
			}
			str[k++] = list->content[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
	return (1);
}

int	char_count_up_to_newline(t_list *list)
{
	int	i;
	int	count;

	if (NULL == list)
		return (0);
	count = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				count++;
				return (count);
			}
			i++;
			count++;
		}
		list = list->next;
	}
	return (count);
}

void	free_memory(t_list **list, char *buf)
{
	t_list	*tmp;

	if (buf != NULL)
		free(buf);
	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->content)
			free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

