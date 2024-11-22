/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:35:11 by nastamid          #+#    #+#             */
/*   Updated: 2024/11/22 18:09:05 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list				*get_last_node(t_list *list);

char				*get_combined_str(t_list *list);
char				*get_next_line(int fd);

int					contains_newline(t_list *list);
int					char_count_up_to_newline(t_list *list);

int					old_to_new_list(t_list **list, t_list **new_list);
int					copy_content(t_list *list, char *str);
int					create_list(t_list **list, int fd);
void				free_memory(t_list **list, char *buf);

#endif