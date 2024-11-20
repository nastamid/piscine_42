CFILES = get_next_line.c get_next_line_utils.c gnl_runner.c
OUTPUT = gnl_program
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER)

BUFFER = 42

build:
	cc $(CFILES) $(CFLAGS) -g -o $(OUTPUT)

smallbuf:
	$(MAKE) run BUFFER=1

bigbuf:
	$(MAKE) run BUFFER=10000000

run: build
	./$(OUTPUT) text.txt

clean:
	rm -f $(OUTPUT)

valgrind: build
	valgrind --leak-check=full ./$(OUTPUT) text.txt
