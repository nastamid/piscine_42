# Basic configuration
NAME = libft.a
CC = cc
CFLAGS = -Wextra -Werror -Wall -MP -MD

# Source files
CFILES = $(wildcard ./*.c)
BONUS_CFILES = $(wildcard ./*_bonus.c)

# Object files
OBJECTS = $(CFILES:.c=.o)
BONUS_OBJECTS = $(BONUS_CFILES:.c=.o)

# Dependency files
DEPFILES = $(CFILES:.c=.d)
BONUS_DEPFILES = $(BONUS_CFILES:.c=.d)

# Build the library without bonus files
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

# Build the library with bonus files
bonus: $(NAME) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean temporary files
clean_temp:
	rm -f $(OBJECTS) $(BONUS_OBJECTS) $(DEPFILES) $(BONUS_DEPFILES)

# Clean all generated files
clean: clean_temp
	rm -f $(NAME)

# Force clean and rebuild
fclean: clean

re: fclean all

# Mark targets as not files
.PHONY: all clean clean_temp fclean re bonus

# Include the dependency files
-include $(DEPFILES) $(BONUS_DEPFILES)
