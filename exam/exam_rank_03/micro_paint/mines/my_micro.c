#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

typedef struct s_area
{
	int		width;
	int		height;
	char	backgroud;
}				t_area;

typedef struct s_square
{
	char			type;
	float			x;
	float			y;
	float			width;
	float			height;
	char			color;
}				t_square;

#define ERR_ARG "Error: argument\n"
#define ERR_OPR "ERROR: Operation file corrupted\n"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error_return(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);

}

void	free_all(char **ret, int max)
{
	int	i;

	i = 0;
	while (i < max)
		free(ret[i++]);
	free(ret);
	return ;
}

char	**get_zone(FILE *target)
{
	char	**ret;
	int		err;
	t_area	zone;
	int		i;

	err = 0;
	err = fscanf(target, "%d  %d %c\n", &zone.width, &zone.height, &zone.backgroud);	if (err != 3 || err == -1)
		return (NULL);
	ret = malloc(sizeof(char *) * (zone.height + 1));
	if (!ret)
		return (NULL);
	ret[zone.height] = 0;
	i = 0;
	while (i < zone.height)
	{
		ret[i] = malloc(sizeof(char) * (zone.width + 1));
		if (!ret[i])
		{
			free_all(ret, i);
			return (NULL);
		}
		memset(ret[i], zone.backgroud, zone.width + 1);
		ret[i][zone.width] = '\n';
		ret[i][zone.width + 1] = 0;
		i++;
	}
	return (ret);
}

int main(int ac, char **av)
{
	FILE	*target;
	char	**paper;

	if (ac != 2)
		return (error_return(ERR_ARG));
	else
	{
		target = fopen(av[1], "r");
		if (!target)
			return (error_return(ERR_OPR));
		paper = get_zone(target);
		if (!paper)
			return (error_return(ERR_OPR));
		for (int i = 0; paper[i]; i++)
			printf("%s", paper[i]);
		/*
		 * make zone
		 * get square 
		 * */
	}
	return (0);
}
