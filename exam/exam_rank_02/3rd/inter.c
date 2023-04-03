#include <unistd.h>

int	ft_endnl(void)
{
	write(1, "\n", 1);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_str_set(char *str, int limit)
{
	int	i;

	i = -1;
	while (++i <= limit)
		str[i] = 0;
}

void	ft_put_to_str(char *str, char c, int limit)
{
	int	i;

	i = 0;
	if (str[0] == 0)
	{
		str[0] = c;
		return ;
	}
	while (i < limit)
	{
		if (str[i] == 0)
		{
			str[i] = c;
			break ;
		}
		else if (str[i] == c)
				break ;
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		limit;
	char	str[7000000];

	if (ac != 3)
	{
		ft_endnl();
		return(0);
	}
	limit = ft_strlen(av[1]);
	ft_str_set(str, limit);
	i = -1;
	while(++i < limit)
	{
		j = -1;
		while(av[2][++j])
		{
			if (av[1][i] == av[2][j])
			{
				ft_put_to_str(str, av[1][i], limit);
				break ;
			}
		}
	}
	limit = ft_strlen(str);
	write(1, str, limit);
	ft_endnl();
	return (0);
}
