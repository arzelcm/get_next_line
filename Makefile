all:
	cc -Wall -Werror -Wextra -g get_next_line_utils.c  get_next_line.c tests/main.c -o main -D BUFFER_SIZE=1

m: all
	./main
	
leaks: all
	leaks -quiet -fullContent -atExit -- ./main

