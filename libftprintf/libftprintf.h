/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:27:31 by nastamid          #+#    #+#             */
/*   Updated: 2024/09/30 17:59:18 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

int	print_char(char c);
int	print_string(char *str);
int	print_digit(int digit);
int	print_pointer(void *ptr);
int	ft_printf(const char *, ...);

#endif