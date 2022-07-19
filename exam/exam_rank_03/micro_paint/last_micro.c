#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct s_paper
{
	int		width;
	int		height;
	char	back;
}		t_paper;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	draw;
}		t_rect;

#define TRUE 1
#define FALSE 0
#define ERR_ARG "Error: argument\n"
#define ERR_OPR "Error: Operation file corrupted\n"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_error(char *str)
{
	write (1, str, ft_strlen(str));
	return (1);
}

void	clear_all(char *str, FILE *target)
{
	fclose(target);
	free(str);
}

int	is_back(t_paper *paper)
{
	if (paper->width < 0 || paper->width > 300)
		return (TRUE);
	if (paper->height < 0 || paper->height > 300)
		return (TRUE);
	if (paper->back < 32 || paper->back > 126)
		return (TRUE);
	return (FALSE);
}

char	*make_paper(t_paper *paper, FILE *target)
{
	char	*ret;
	int		err;

	err = fscanf(target, "%d %d %c\n", &(paper->width), &(paper->height), &(paper->back));
	if (err != 3)
		return (NULL);
	if (is_back(paper))
		return (NULL);
	ret = calloc((paper->height * paper->width + 1), sizeof(char));
	if (!ret)
		return (NULL);
	memset(ret, paper->back, paper->width * paper->height);
	return (ret);
}

int	is_rect(t_rect *rect)
{
	float	check;

	check = 0.00000000;
	if (rect->type != 'r' && rect->type != 'R')
		return (TRUE);
	if (rect->width <= check || rect->height <= check)
		return (TRUE);
	if (rect->draw < 32 || rect->draw > 126)
		return (TRUE);
	return (FALSE);
}

int	check_rec(float x, float y, t_rect *rect)
{
	float	check;
	float	xbr = rect->x + rect->width;
	float	ybr = rect->y + rect->height;

	check = 1.00000000;
	if (x < rect->x || x > rect->x + rect->width || y < rect->y || y > rect->y + rect->height)
		return (0);
	if (x - rect->x < check || xbr - x < check || y - rect->y < check || ybr - y < check)
		return (2);
	return (1);
}

void	draw_rects(t_paper paper, t_rect *rect, char **draw)
{	
	int	x;
	int	y;
	int	rec_con;

	y = 0;
	while (y < paper.height)
	{
		x = 0;
		while (x < paper.width)
		{
			rec_con = check_rec((float)x, (float)y, rect);
			if (rect->type == 'r' && rec_con == 2)
				(*draw)[y * paper.height + x] = rect->draw;
			if (rect->type =='R' && rec_con)
				(*draw)[y * paper.height + x] = rect->draw;
			x++;
		}
		y++;
	}
	return ;
}

int	get_rects(t_paper paper, t_rect *rect, char **draw, FILE *target)
{
	int err;

	err = fscanf(target, "%c %f %f %f %f %c\n", &(rect->type), &(rect->x), &(rect->y), &(rect->width), &(rect->height), &(rect->draw));
	if (err!= 6)
		return (TRUE);
	while (err == 6)
	{
		if (is_rect(rect))
			return (TRUE);
		draw_rects(paper, rect, draw);
		err = fscanf(target, "%c %f %f %f %f %c\n", &(rect->type), &(rect->x), &(rect->y), &(rect->width), &(rect->height), &(rect->draw));
	}
	return (FALSE);
}

void	print_draw(char *str, t_paper paper)
{
	int	i;

	i = 0;
	while (i < paper.height)
	{
		write(1, str + (i * paper.height), paper.height);
		write(1, "\n", 1);
		i++;
	}
	return ;
}

int main(int ac, char **av)
{
	FILE 		*target;
	t_paper		paper;
	t_rect		rect;
	char		*draw;

	if (ac != 2)
		return (print_error(ERR_ARG));
	target = fopen(av[1], "r");
	if (!target)
		return (print_error(ERR_OPR));
	draw = make_paper(&paper, target);
	if (!draw)
	{
		clear_all(draw, target);
		return (print_error(ERR_OPR));
	}
	if (get_rects(paper, &rect, &draw, target))
	{
		clear_all(draw, target);
		return (print_error(ERR_OPR));
	}
	print_draw(draw, paper);
	clear_all(draw, target);
	return (0);
}
