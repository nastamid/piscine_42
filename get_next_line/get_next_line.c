/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:35:13 by nastamid          #+#    #+#             */
/*   Updated: 2024/11/22 17:56:15 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	old_to_new_list(t_list **list, t_list **new_list)
{
	t_list	*last_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	last_node = get_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[i++])
		buf[j++] = last_node->content[i];
	buf[j] = '\0';
	(*new_list)->content = buf;
	(*new_list)->next = NULL;
	free_memory(list, NULL);
	if (new_list && (*new_list)->content[0])
		*list = *new_list;
	else
		free_memory(new_list, NULL);
	return (1);
}

char	*get_combined_str(t_list *list)
{
	int		str_len;
	char	*combined_str;

	if (list == NULL)
		return (NULL);
	str_len = char_count_up_to_newline(list);
	combined_str = malloc(str_len + 1);
	if (combined_str == NULL)
		return (NULL);
	if (!copy_content(list, combined_str))
	{
		free(combined_str);
		return (NULL);
	}
	return (combined_str);
}

int	append(t_list **list, char *content)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = get_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (0);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = content;
	new_node->next = NULL;
	return (1);
}

int	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!contains_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (0);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return (0);
		}
		buf[char_read] = '\0';
		if (!append(list, buf))
		{
			free(buf);
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;
	t_list			*new_list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!create_list(&list, fd))
	{
		free_memory(&list, NULL);
		return (NULL);
	}
	if (list == NULL)
		return (NULL);
	next_line = get_combined_str(list);
	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	if (!old_to_new_list(&list, &new_list))
	{
		free(new_list);
		free(next_line);
		free_memory(&list, NULL);
		return (NULL);
	}
	return (next_line);
}
