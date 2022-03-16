/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:45:24 by haryu             #+#    #+#             */
/*   Updated: 2022/03/17 02:05:27 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_put(t_mlx *vars, t_img *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, x, y);
	return (0);
}

int	map_checker(char *map, t_module **init)
{
	unsigned int	*x;
	unsigned int	*y;
	char			*map_dir;

	x = &(*init)->map.position.x;
	y = &(*init)->map.position.y;
	if (map[0] == '1')
		map_dir = MAP_DIR_1;
	else if (map[0] == '2')
		map_dir = MAP_DIR_2;
	else if (map[0] == '3')
		map_dir = MAP_DIR_3;
	else if (map[0] == '4')
		map_dir = MAP_DIR_4;
	map_resolution(map_dir, init, x, y);
	return (0);
}

int	map_resolution(char *map, t_module **init, unsigned int *x, unsigned int *y)
{
	int		fd;
	int		width;
	int		height;
	t_rule	*rules;

	*x = 0;
	*y = 1;
	rules = &(*init)->map.rule;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit (1);
	if (map_error(fd, rules, x, y))
	{
		printf("Error\n");
		exit(1);
	}
	*x = SIZE * (*x - 1);
	*y = SIZE * (*y - 1);
	close(fd);
	if (*x > MAX_WIDTH || *y > MAX_HEIGHT)
	{
		printf("The resolution of a current map file is too big.\n");
		exit (1);
	}
	printf("%d %d %d\n", rules->starting, rules->collect, rules->exit);
	return (0);
}
