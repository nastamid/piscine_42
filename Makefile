NAME = libft.a
CODEDIRS = .
INCDIRS = .
CC = cc
# Generate files that encode make rules for .h dependencies
DEPFLAGS = -MP -MD
CFLAGS = -Wextra -Werror -Wall $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)
# find All .c files
CFILES = $(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))
OBJECTS = $(patsubst %.c, %.o, $(CFILES))
DEPFILES = $(patsubst %.c, %.d, $(CFILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	@echo "Build complete. Cleaning up..."
	@$(MAKE) --no-print-directory clean_temp

# We need only .c file dependency here that's why we use $<
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean_temp:
	@echo "Cleaning temporary files..."
	@rm -f $(OBJECTS) $(DEPFILES)

clean:
	@echo "Cleaning all generated files..."
	@rm -f $(OBJECTS) $(DEPFILES) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean clean_temp fclean re

# Include the dependency files
-include $(DEPFILES)