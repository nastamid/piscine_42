make
make clean
cc -Wextra -Wall -Werror ./testprintf/test_ft_print.c -L. -lftprintf -L./libft -lft -I. -I./libft && ./a.out
[ -e ./a.out ] && rm ./a.out