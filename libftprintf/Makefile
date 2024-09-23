# Basic configuration
NAME = libftprint.a
CC = cc
CFLAGS = -std=c2x -Wextra -Werror -Wall  -g 

# Source files
CFILES = ft_printf.c

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

# Mark targets as not files
.PHONY: all clean fclean re 