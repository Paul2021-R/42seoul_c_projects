#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	k;
	int	limit;
	int	flag;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = -1;
	limit = ft_strlen(av[1]);
	while(++i < limit)
	{
		flag = 0;
		j = -1;
		while(av[1][++j])
		{
			if (av[1][i] == av[1][j] && i > j)
				break ;
			if (j == limit - 1 && flag == 0)
				flag += 1;
		}
		k = -1;
		while (av[2][++k])
		{
			if (av[1][i] == av[2][k])
			{
				flag += 1;
				break ;	
			}
		}
		if (flag == 2)
			write(1, &av[1][i], 1);
	}
	return (0);

}

/*
 * inter 핵심 사항 정리 
 * 1. 양쪽에 모두 나와야 한다
 * */
