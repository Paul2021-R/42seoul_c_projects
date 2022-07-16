#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_set_to_zero(char *s, int limit)
{
	int	i;

	i = -1;
	while(++i < limit)
		s[i] = 0;
	return ;
}

void	ft_put_char_to_str(char *str, char c, int limit)
{
	int	i;

	if (str[0] == 0)
	{
		str[0] = c;
		return ;
	}
	i = -1;
	while(++i < limit)
	{
		if (str[i] == 0)
		{
			str[i] = c;
			break ;
		}
		if (str[i] == c)
			break ;
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
		write(1, "\n", 1);
		return (0);
	}
	limit = ft_strlen(av[1]);
	limit += ft_strlen(av[2]);
	ft_set_to_zero(str, limit);
	i = -1;
	while(av[1][++i])
		ft_put_char_to_str(str, av[1][i], limit);
	i = -1;
	while(av[2][++i])
		ft_put_char_to_str(str, av[2][i], limit);
	limit = ft_strlen(str);
	write(1, str, limit);
	write(1, "\n", 1);
	return (0);
}

