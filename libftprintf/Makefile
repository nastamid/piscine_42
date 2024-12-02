# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 13:50:15 by nastamid          #+#    #+#              #
#    Updated: 2024/12/02 13:30:57 by nastamid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basic configuration
NAME = libftprintf.a
CC = cc
CFLAGS = -std=c2x -Wextra -Werror -Wall  -g  

# Source files
CFILES = ft_strlen.c\
	ft_strdup.c\
	ft_itoa.c\
	ft_printf.c\
	print_char.c\
	print_string.c\
	print_digit.c\
	print_pointer.c\
	print_hex.c\
	

# Object files
OBJECTS = $(CFILES:.c=.o)

# Build the library
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $?

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean all generated files except library
clean: 
	rm -f $(OBJECTS)

# Force clean all generated files and library too
fclean: clean
	rm -f $(NAME) 

# Force Rebuild - Force Clean and Rebuild
re: fclean all

run:
	cc -Wextra -Wall -Werror ft_printf.c -L. -lftprintf  -I.  && ./a.out

run_tests:
	gcc -Wextra -Wall -Werror ../tests/testprintf/test_ft_print.c -L. -lftprintf -I.  && ./a.out

run_funcheck:
	gcc  -no-pie -g ../tests/testprintf/funcheck_ft_printf.c -L. -lftprintf -I.  && ./a.out
	funcheck ./a.out

# Mark targets as not files
.PHONY: all clean fclean re 