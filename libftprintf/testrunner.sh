make
make clean
gcc -Wextra -Wall -Werror ../tests/testprintf/test_ft_print.c -L. -lftprintf -I.  && ./a.out
# [ -e ./a.out ] && rm ./a.out