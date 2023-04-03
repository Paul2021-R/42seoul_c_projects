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
	while (i < max && ret[i])
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

char	**get_zone(FILE *target)
{
	char	**ret;
	int		err;
	t_area	zone;
	int		i;

	err = 0;
	err = fscanf(target, "%d  %d %c\n", &zone.width, &zone.height, &zone.backgroud);	if (err != 3 || err == -1 || err > 3)
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

void	printf_paper(char **paper)
{
	for (int i = 0; paper[i]; i++)
		write(1, paper[i], ft_strlen(paper[i]));
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
	int		rec_type;

	rec_type = 0;
	check = 1.00000000;
	/*
	 * type : 0 -> r
	 * type : 1 -> R
	 * return value 
	 *  0 : not pointer
	 *  1 : r case && outline 
	 * 	2 : R case && it & out 
	 * */
	if (draw.type == 'R')
		rec_type = 1;
	xbr = draw.x + draw.width;
	ybr = draw.y + draw.height;
	if ((x >= draw.x && x <= xbr) && (y >= draw.y && y <= ybr))
	{
		if ((x > draw.x && x < draw.x + check) || (x < xbr && x >= xbr - check) || (y > draw.y && y < draw.y + check ) || (y < ybr && y >= ybr - check))
			return (1 + rec_type);
		else if (rec_type == 1)
			return (1 + rec_type);
		else
			return (0);
	}
	return (0);
}

void	draw_square(char **paper, t_square draw)
{
	int		x;
	int		y;
	int		rec;

	y = 0;
	while (paper[y])
	{
		x = 0;
		while (paper[y][x])
		{
			rec = is_rec((float)x, (float)y, draw);
			if (draw.type == 'r' && rec == 1)
				paper[y][x] = draw.color;
			else if (draw.type == 'R' && rec == 2)
				paper[y][x] = draw.color;
			x++;
		}
		y++;
	}
}

int	get_square(FILE *target, char **paper)
{
	t_square	square;
	int			err;

	while ((err = fscanf(target, "%c %f %f %f %f %c\n", &square.type, &square.x, &square.y, &square.width, &square.height, &square.color)) == 6)
	{
		if (check_square(square))
			return (TRUE);
		draw_square(paper, square);
	}
	printf_paper(paper);
	if (err != -1)
		return (TRUE);
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
		if (get_square(target, paper))
			return (error_return(ERR_OPR));
		free_all(paper, INTMAX);
		fclose(target);
	}
	//return (0);
	atexit(return_leaks_check());
}
