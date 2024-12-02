NAME = fdf.out
CFILES = get_next_line.c get_next_line_utils.c
TIME_TEST_FILE = gnl_time_test_runner.c
TEST_FILE = gnl_test_runner.c
CFLAGS = -Wall -Wextra -Werror 
MLXFLAG = -lmlx -lXext -lX11

all:
	cc $(CFILES) $(TEST_FILE) $(CFLAGS) $(CBUFFER) -g -o $(NAME)


clean:
	rm -f $(OUTPUT)

fclean:
	clean 
# todo:

re:
#todo

valgrind: build
	valgrind --leak-check=full ./$(NAME)