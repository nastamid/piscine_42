NAME = libft.a
CODEDIRS = .
BONUSDIRS = bonus
INCDIRS = .
CC = cc
DEPFLAGS = -MP -MD
CFLAGS = -Wextra -Werror -Wall $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)

# Find all .c files in CODEDIRS and BONUSDIRS
CFILES = $(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))
BONUS_CFILES = $(foreach D, $(BONUSDIRS), $(wildcard $(D)/*.c))

OBJECTS = $(patsubst %.c, %.o, $(CFILES))
BONUS_OBJECTS = $(patsubst %.c, %.o, $(BONUS_CFILES))

DEPFILES = $(patsubst %.c, %.d, $(CFILES))
BONUS_DEPFILES = $(patsubst %.c, %.d, $(BONUS_CFILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^
	@echo "Build complete. Cleaning up..."
	@$(MAKE) --no-print-directory clean_temp

bonus: $(BONUS_OBJECTS)
	ar rcs $(NAME) $^
	@echo "Bonus build complete. Cleaning up..."
	@$(MAKE) --no-print-directory clean_temp

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean_temp:
	@echo "Cleaning temporary files..."
	@rm -f $(OBJECTS) $(BONUS_OBJECTS) $(DEPFILES) $(BONUS_DEPFILES)

clean:
	@echo "Cleaning all generated files..."
	@rm -f $(OBJECTS) $(BONUS_OBJECTS) $(DEPFILES) $(BONUS_DEPFILES) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean clean_temp fclean re bonus

# Include the dependency files
-include $(DEPFILES) $(BONUS_DEPFILES)
