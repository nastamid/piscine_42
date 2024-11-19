/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:35:13 by nastamid          #+#    #+#             */
/*   Updated: 2024/11/20 14:45:00 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cleanup_list(t_list **list)
{
	t_list	*last_node;
	t_list	*node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	node = malloc(sizeof(t_list));
	if (buf == NULL || node == NULL)
		return ;
	last_node = get_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[i])
	{
		i++;
		buf[j++] = last_node->content[i];
	}
	buf[j] = '\0';
	node->content = buf;
	node->next = NULL;
	free_memory(list, node, buf);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = char_count_up_to_newline(list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_content(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *content)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = get_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = content;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!contains_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	cleanup_list(&list);
	return (next_line);
}
