/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:27:31 by nastamid          #+#    #+#             */
/*   Updated: 2024/10/01 14:43:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>

int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);

int		print_char(char c);
int		print_string(char *str);
int		print_digit(int digit);
int		print_udigit(unsigned int digit);
int		print_pointer(void *ptr);
int		print_hex(long n, bool is_uppercase);
int		vft_printf(const char *format, va_list args);
int		ft_printf(const char *, ...);

#endif