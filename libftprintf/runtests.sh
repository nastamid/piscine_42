cc -Wextra -Wall -Werror ./testprintf/printf_test.c -L. -lftprintf -L./libft -lft -I. -I./libft && ./a.out
[ -e ./a.out ] && rm ./a.out