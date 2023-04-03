#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ERR_ARG "Error: argument\n"
#define ERR_OPR "Error: Operation file corrupted\n"

typedef struct s_zone
{
	int		width;
	int		height;
	char	back;
}				t_zone;

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	draw;
}				t_circle;

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
	write(1, str, ft_strlen(str));
	return (TRUE);
}

void	clear_all(char *target, FILE *file)
{
	free(target);
	fclose(file);
}

void	write_picture(char *picture, t_zone back)
{
	int	i;

	i = 0;
	while (i < back.height)
	{
		write(1, picture + (i * back.height), back.height);
		write(1, "\n", 1);
		i++;
	}
}

int	is_back(t_zone *back)
{
	if (back->width < 0 || back->width > 300)
		return (TRUE);
	if (back->height < 0 || back->height > 300)
		return (TRUE);
	if (back->back < 32 || back->back > 126)
		return (TRUE);
	return (FALSE);
}

char	*make_back(FILE *target, t_zone *back)
{
	char	*ret;
	int		err;

	err = fscanf(target, "%d %d %c\n", &(back->width), &(back->height), &(back->back));
	if (err != 3)
		return (NULL);
	if (is_back(back))
		return (NULL);
	ret = calloc(back->width * back->height + 1, sizeof(char));
	if (!ret)
		return (NULL);
	memset(ret, back->back, back->width * back->height);
	return (ret);
}

int	is_circle(t_circle cir)
{
	float	check;

	check = 0.00000000;
	if (cir.type != 'c'&& cir.type != 'C')
		return (TRUE);
	if (cir.radius <= check)
		return (TRUE);
	return (FALSE);
}

int	check_circle(float x, float y, t_circle cir)
{
	float check;
	float sqrt;

	check = 1.00000000;
	sqrt = sqrtf((x - cir.x) * (x - cir.x) + (y - cir.y) * (y - cir.y));
	if (sqrt > cir.radius)
		return (0);
	if (cir.radius - sqrt < check)
		return (2);
	return (1);
}

void	draw_circle(t_circle cir, t_zone back, char **paper)
{
	int	cir_c;
	int	x;
	int	y;

	y = 0;
	while (y < back.height)
	{
		x = 0;
		while (x < back.width)
		{
			cir_c = check_circle((float)x, (float)y, cir);
			if (cir.type == 'c' && cir_c == 2)
				(*paper)[y * back.height + x] = cir.draw;
			if (cir.type == 'C' && cir_c)
				(*paper)[y * back.height + x] = cir.draw;
			x++;
		}
		y++;
	}

	return ;
}

int	get_circle(FILE *target, t_zone back, char **paper)
{
	t_circle	cir;
	int			err;

	while ((err = fscanf(target, "%c %f %f %f %c\n", &(cir.type), &(cir.x), &(cir.y), &(cir.radius), &(cir.draw))) && err == 5)
	{
		if (is_circle(cir))
			return (TRUE);
		draw_circle(cir, back, paper);
	}
	if (err != -1)
		return (TRUE);
	return (FALSE);
}

int main(int ac, char **av)
{
	FILE 		*target;
	t_zone		back;
	char		*picture;

	if (ac != 2)
		return (print_error(ERR_ARG));
	target = fopen(av[1], "r");
	if (!target)
		return (print_error(ERR_OPR));
	picture = make_back(target, &back);
	if (!picture)
	{
		fclose(target);
		return (print_error(ERR_OPR));
	}
	if (get_circle(target, back, &picture))
	{
		clear_all(picture, target);
		return (print_error(ERR_OPR));
	}
	write_picture(picture, back);
	clear_all(picture, target);
	return (0);
}
