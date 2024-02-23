all:
	cc -Wall -Werror -Wextra -g get_next_line_utils.c  get_next_line.c tests/main.c -o main -D BUFFER_SIZE=1
bonus:
	cc -Wall -Werror -Wextra -g get_next_line_utils_bonus.c  get_next_line_bonus.c tests/main.c -o main -D BUFFER_SIZE=1
m: bonus
	./main

paco:
	mv Makefile tests
	-~/francinette/tester.sh
	mv tests/Makefile .

pacos:
	mv Makefile tests
	-~/francinette/tester.sh -s -tm 600
	mv tests/Makefile .
	
leaks: all
	leaks -quiet -fullContent -atExit -- ./main
