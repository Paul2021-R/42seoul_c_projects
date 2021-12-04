#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*ret;
	int		fd;
	mode_t	mode;

	(void)ac;
	mode = S_IRWXU | S_IRUSR | S_IWUSR | S_IXUSR;
	fd = open("test.txt", O_RDWR, mode);
	if (fd == -1)
	{
		perror("Fail\n");
		exit(1);
	}
	for (int i = 0 ; i < atoi(av[1]) ; i++)
	{
		ret = get_next_line(fd);
	}
	printf("%s\n", ret);
	close(fd);
	return (0);

}
