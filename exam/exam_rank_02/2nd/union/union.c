#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_put_str(char *str, char c, int limit)
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
		else if (str[i] == c)
			break ;
	}
	return ;

}

int	main(int ac, char **av)
{
	int		i;
	char	str[7000000];
	int		limit;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	limit = ft_strlen(av[1]);
	limit += ft_strlen(av[2]);
	i = -1;
	while (++i < limit)
		str[i] = 0;
	i = -1;
	while(av[1][++i])
		ft_put_str(str, av[1][i], limit);
	i = -1;
	while (av[2][++i])
		ft_put_str(str, av[2][i], limit);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	return (0);
}
