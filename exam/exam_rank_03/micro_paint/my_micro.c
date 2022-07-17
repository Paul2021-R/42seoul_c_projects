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
#define ERR_OPR "Error: Operation file corrupted\n"
#define TRUE 1
#define FALSE 0
#define INTMAX 2147483647

void	printf_paper(char **paper, int max_x, int max_y);

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
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

int	check_zone(t_area *zone)
{
	if (zone->width > 300 || zone->width < 0)
		return (TRUE);
	if (zone->height > 300 || zone->height < 0)
		return (TRUE);
	if (zone->backgroud < 33 || zone->backgroud >= 127)
		return (TRUE);
	return (FALSE);
}

char	**get_zone(FILE *target, int *x, int *y)
{
	char	**ret;
	int		err;
	t_area	zone;
	int		i;

	err = 0;
	err = fscanf(target, "%d %d %c\n", &zone.width, &zone.height, &zone.backgroud);
	if (err != 3 || err == -1 || err > 3)
		return (NULL);
	if (check_zone(&zone))
		return (NULL);
	ret = malloc(sizeof(char *) * (zone.height + 1));
	if (!ret)
		return (NULL);
	ret[zone.height] = 0;
	i = 0;
	while (i < zone.height)
	{
		ret[i] = malloc(sizeof(char) * (zone.width + 2));
		if (!ret[i])
		{
			free_all(ret, i);
			return (NULL);
		}
		for (int j = 0;j < zone.width ; j++)
			ret[i][j] = zone.backgroud;
		ret[i][zone.width] = '\n';
		ret[i][zone.width + 1] = 0;
		i++;
	}
	*x = zone.width;
	*y = zone.height;
	return (ret);
}

void	printf_paper(char **paper, int max_x, int max_y)
{
	for (int i = 0; i < max_y; i++)
		write(1, paper[i], max_x + 1);
	return ;
}

int	check_square(t_square square)
{
	float	check;

	check = 0.00000000;
	if (square.type != 'r' && square.type != 'R')
		return (TRUE);
	if (square.width <= check || square.height <= check)
		return (TRUE);
	return (FALSE);
}

int		is_rec(float x, float y, t_square draw)
{
	float	xbr;
	float	ybr;
	float	check;

	check = 1.00000000;
	xbr = draw.x + draw.width;
	ybr = draw.y + draw.height;
	if ((x < draw.x) || (xbr < x) || (y < draw.y) || (ybr < y))
		return (0);
	if (((x - draw.x) < check) || xbr - x < check || (y - draw.y) < check || ybr - y < check)
		return (2);
	return (1);
}

void	draw_square(char **paper, t_square draw, int max_x, int max_y)
{
	int		x;
	int		y;
	int		rec;

	y = 0;
	while (y <  max_y)
	{
		x = 0;
		while (x < max_x)
		{
			rec = is_rec(x, y, draw);
			if ((draw.type == 'r' && rec == 2) || (draw.type == 'R' && rec))
				paper[y][x] = draw.color;
			x++;
		}
		y++;
	}
}

int	get_square(FILE *target, char **paper, int max_x, int max_y)
{
	t_square	square;
	int			err;

	while ((err = fscanf(target, "%c %f %f %f %f %c\n", &square.type, &square.x, &square.y, &square.width, &square.height, &square.color)) == 6)
	{
		if (check_square(square))
			return (TRUE);
		draw_square(paper, square, max_x, max_y);
	}
	if (err != -1)
		return (TRUE);
	printf_paper(paper, max_x, max_y);
	return (FALSE);
}

void	*return_leaks_check(void)
{
	system("leaks a.out");
	return (0);
}

int main(int ac, char **av)
{
	FILE	*target;
	char	**paper;
	int		x, y;

	if (ac != 2)
		return (error_return(ERR_ARG));
	else
	{
		target = fopen(av[1], "r");
		if (!target)
			return (error_return(ERR_OPR));
		paper = get_zone(target, &x, &y);
		if (!paper)
			return (error_return(ERR_OPR));
		if (get_square(target, paper, x, y))
			return (error_return(ERR_OPR));
		free_all(paper, y);
		fclose(target);
	}
	return (0);
	//atexit(return_leaks_check());
}
