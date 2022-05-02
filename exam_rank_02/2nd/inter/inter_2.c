#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

void	both_put(char *str, char c, int limit)
{
	int	i;

	i = -1;
	while(++i < limit)
	{
		if ((str)[0] == 0)
		{
			(str)[0] = c;
			break ;
		}
		if ((str)[i] == 0)
		{
			(str)[i] = c;
			break ;
		}
		else if ((str)[i] == c)
			return ;
	}
	return ;
}

void	ft_putstr(char *str, int len)
{
	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
	return;
}

int	main(int ac, char **av)
{
	int 	i;
	int 	j;
	int		limit;
	char	str[7000000];
	
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	limit = ft_strlen(av[1]);
	i = -1;
	while (++i < limit)
	{
		j = -1;
		while(av[2][++j])
		{
			if (av[1][i] == av[2][j])
			{
				both_put(str, av[1][i], limit);
				break ;
			}
			
		}
	}
	ft_putstr(str, limit);
	return (0);
}

