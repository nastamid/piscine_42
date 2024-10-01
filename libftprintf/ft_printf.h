/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:27:31 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/01 10:23:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	print_char(char c);
int	print_string(char *str);
int	print_digit(int digit);
int	print_udigit(unsigned int digit);
int	print_pointer(void *ptr);
int	vft_printf(const char *format, va_list args);
int	ft_printf(const char *, ...);

#endif