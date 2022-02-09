#include <stdio.h>

int main(int ac, char **av)
{
	int  i = 1;

	while (i <= ac)
	{
		printf("%s\a\n",av[i++]);
		if (i == ac) break ;
	}
	return (0);
}
