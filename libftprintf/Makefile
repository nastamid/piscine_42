# Basic configuration
NAME = libftprintf.a
CC = cc
CFLAGS = -std=c2x -Wextra -Werror -Wall  -g -L./libft -lft -I./libft 

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
CFILES = ft_printf.c\
	print_digit.c\
	print_char.c\
	print_string.c

# Object files
OBJECTS = $(CFILES:.c=.o)

# Build the library
all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS)
	ar rcs $@ $?

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean all generated files except library
clean: 
	rm -f $(OBJECTS)
	@$(MAKE) -C $(LIBFT_DIR) clean

# Force clean all generated files and library too
fclean: clean
	rm -f $(NAME) 
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Force Rebuild - Force Clean and Rebuild
re: fclean all

# Mark targets as not files
.PHONY: all clean fclean re 