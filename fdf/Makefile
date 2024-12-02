# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibs/libft/include -Ilibs/ft_printf/include  -Ilibs/mlx_linux/include
LDFLAGS = -Llib -Llibs/mlx_linux

# Libraries to link against
LIBS = -lft -lftprintf -lmlx_Linux -L./libs -lXext -lX11 -lm -lz

# Project details
NAME = fdf.out

# Explicitly list your source files here
SRC = src/fdf.c # Replace with your actual source file paths

# Automatically generate object files names from source files
OBJ = $(SRC:.c=.o)

# Targets
.PHONY: all clean fclean re

all: $(NAME)

# Rule for creating the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)

# Rule for creating object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up everything including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild and run
run: re
	./$(NAME)

# Rebuild everything
re: fclean all