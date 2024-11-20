CFILES = get_next_line.c get_next_line_utils.c
TIME_TEST_FILE = gnl_time_test_runner.c
TEST_FILE = gnl_test_runner.c
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

run_time_test: $(CFILES) $(TIME_TEST_FILE)
	cc $(CFILES) $(TIME_TEST_FILE) $(CFLAGS) -g -o $(OUTPUT)
	./$(OUTPUT)

run_test: $(CFILES) $(TEST_FILE)
	cc $(CFILES) $(TEST_FILE) $(CFLAGS) -g -o $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)

valgrind: build
	valgrind --leak-check=full ./$(OUTPUT) text.txt
