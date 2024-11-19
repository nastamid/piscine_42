CFILES = get_next_line.c get_next_line_utils.c
OUTPUT = gnl_program
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

build:
	cc $(CFILES) $(CFLAGS) -g -o $(OUTPUT)

run: build
	./$(OUTPUT) text.txt

clean:
	rm -f $(OUTPUT)

valgrind: build
	valgrind --leak-check=full ./$(OUTPUT) text.txt
