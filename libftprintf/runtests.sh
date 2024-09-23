cc -Wextra -Wall -Werror test_file.c -L. -lftprintf -L./libft -lft -I./libft && ./a.out
[ -e ./a.out ] && rm ./a.out