/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:58:17 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/05 12:42:28 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>

int				ft_atoi(char *str);
int				ft_isalpha(int c);
void			ft_bzero(void *s, int n);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memset(void *s, int c, int n);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strlcpy(char *dest, char *src, int size);
void			*ft_memcpy(void *destination, const void *source, size_t num);

#endif
