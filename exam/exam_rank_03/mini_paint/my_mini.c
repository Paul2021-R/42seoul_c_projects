#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ERR_ARG "Error: argument\n"
#define ERR_OPR "Error: Operation file corrupted\n"

#define INTMAX 2147483647

typedef struct  s_zone
{
	int		width;
	int		height;
	char	background;
}		t_zone;

typedef struct s_radius
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	draw;
}		t_radius;

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	err_print(char *str)
{
	write(1, str, ft_strlen(str));
	return (TRUE);
}

int	write_paper(char **paper)
{
	int i;

	i = 0;
	while (paper[i])
	{
		write(1, paper[i], ft_strlen(paper[i]));
		i++;
	}
	return (0);
}

void	free_all(char **paper, t_zone background)
{
	int	i;

	i = 0;
	while (i < background.height + 1)
	{
		free(paper[i]);
		i++;
	}
	free(paper);
}

int	is_back(t_zone *background)
{
	if (background->width <= 0 || background->width > 300)
		return (TRUE);
	if (background->height <= 0 || background->height > 300)
		return (TRUE);
	if (background->background <= 31 || background->background > 126)
		return (TRUE);
	return (FALSE);
}

int	make_background(FILE *target, t_zone *background)
{
	int err;

	err = fscanf(target, "%d %d %c\n", &background->width, &background->height, &background->background);
	if (err != 3)
		return (TRUE);
	if (is_back(background))
		return (TRUE);
	return (0);
}

char	**draw_back(t_zone background)
{
	char	**ret;
	int		i;

	ret = malloc(sizeof(char *) * (background.height + 1));
	if (!ret)
		return (NULL);
	ret[background.height] = 0;
	i = 0;
	while (i < background.height)
	{
		ret[i] = malloc(sizeof(char) * (background.width + 2));
		if (!ret[i])
		{
			free_all(ret, background);
			return (NULL);
		}
		memset(ret[i], background.background, background.width);
		ret[i][background.width] = '\n';
		ret[i][background.width + 1] = 0;
		i++;
	}
	return (ret);
}

int	is_circle_condition(t_radius cir)
{
	float	check;

	check = 0.00000000;
	if (cir.type !='c' && cir.type != 'C')
		return (TRUE);
	if (cir.radius <= check)
		return (TRUE);
	return (FALSE);
}

int	is_circle(float x, float y, t_radius cir)
{
	float	sqrt;
	float	check;

	check = 1.00000000;
	sqrt = sqrtf((x - cir.x) * (x - cir.x) + (y - cir.y) * (y - cir.y));
	if (sqrt <= cir.radius)
	{
		if (cir.radius - sqrt < check)
			return (2);
		return (1);
	}
	return (0);
}

void	draw_circle(t_radius cir, char ***paper, t_zone background)
{
	int		circle;
	int		x;
	int		y;

	y = 0;
	while (y < background.height)
	{
		x = 0;
		while (x < background.width)
		{
			circle = is_circle((float)x, (float)y, cir);
			if (cir.type == 'c' && circle == 2)
				(*paper)[y][x] = cir.draw;
			if (cir.type == 'C' && circle)
				(*paper)[y][x] = cir.draw;
			x++;
		}
		y++;
	}
	return ;
}

int	make_circle(FILE *target, t_zone background, char ***paper)
{
	int			err;
	t_radius	cir;	

	while ((err = fscanf(target, "%c %f %f %f %c\n", &cir.type, &cir.x, &cir.y, &cir.radius, &cir.draw)) && err == 5)
	{
		if (is_circle_condition(cir))
			return (TRUE);
		draw_circle(cir, paper, background);
	}
	return (FALSE);
}

int	main(int ac, char **av)
{
	FILE		*target;
	t_zone		background;
	char		**paper;

	if (ac != 2)
		return (err_print(ERR_ARG));
	else
	{
		target = fopen(av[1], "r");
		if (!target)
			return (err_print(ERR_OPR));
		if (make_background(target, &background))
			return (err_print(ERR_OPR));
		paper = draw_back(background);
		if (make_circle(target, background, &paper))
			return (err_print(ERR_OPR));
		write_paper(paper);
		fclose(target);
		free_all(paper, background);
	}
	return (0);
}
