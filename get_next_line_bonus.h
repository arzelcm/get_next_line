#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>

typedef struct	s_fd_repo
{
	int					fd;
	char				*buff;
	struct s_fd_repo	*next;
}	t_fd_repo;

char *get_next_line(int fd);

int ft_strlen(char *s);

int get_line_break_pos(char *str);

char *ft_substr(char *s, int start, int len);

int ft_strlcpy(char *dst, char *src, int dstsize);

#endif
