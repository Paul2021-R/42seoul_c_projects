#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char *line;
	int fd;
	int i;

	fd = open("coucou.txt", O_RDONLY);
	i = 1;
	while(i < 7)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return(0);
}
