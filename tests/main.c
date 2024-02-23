#include "../get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char *auxline;
	// int	fd = 100;
	int	fd = open("tests/test2.txt", O_RDONLY);
	char *line = get_next_line(fd);
	int i = 0;

	while (line)
	{
		printf("%-2i: %s", i + 1, line);
		auxline = get_next_line(fd);
		free(line);
		line = auxline;
		i++;
	}
	if (line)
		free(line);
	close(fd);
	return (0);
}
