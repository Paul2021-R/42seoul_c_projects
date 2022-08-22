#include "microshell.h"
#include <stdio.h>

extern char **envrion;

size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int	i;
	int	start;


	if (argc < 2)
		return (0);
	while (i < argc)
	{
		
	}
	return (0);
}
