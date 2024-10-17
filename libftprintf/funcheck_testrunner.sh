make
make clean
gcc  -no-pie -g ../tests/testprintf/funcheck_ft_printf.c -L. -lftprintf -I.  && ./a.out
funcheck ./a.out
#[ -e ./a.out ] && rm ./a.out