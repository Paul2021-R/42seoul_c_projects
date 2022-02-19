/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:34:42 by haryu             #+#    #+#             */
/*   Updated: 2022/02/20 01:22:03 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_load(t_mlx *vars, t_map *data, char *map_num)
{
	data = malloc(sizeof(t_map) * 1);
	if (!data)
		return (-1);
	if (map_initialize(vars, data))
	{
		printf("error!\n");
		exit(1);
	}
	map_print(vars, data, map_num);
	return (0);
}

int	map_initialize(t_mlx *vars, t_map *data)
{
	data->pass = malloc(sizeof(t_img) * 1);
	data->wall = malloc(sizeof(t_img) * 1);
	data->collect = malloc(sizeof(t_img) * 1);
	data->starting = malloc(sizeof(t_img) * 1);
	data->exit = malloc(sizeof(t_img) * 1);
	if (!(data->pass || data->wall \
				|| data->collect || data->starting || data->exit))
		return (1);
	data->pass->img = mlx_xpm_file_to_image(vars->mlx, \
			PASS, &data->pass->width, &data->pass->height);
	data->wall->img = mlx_xpm_file_to_image(vars->mlx, \
			WALL, &data->wall->width, &data->wall->height);
	data->collect->img = mlx_xpm_file_to_image(vars->mlx, \
			COLLECT, &data->collect->width, &data->collect->height);
	data->starting->img = mlx_xpm_file_to_image(vars->mlx, \
			STARTING, &data->starting->width, &data->starting->height);
	data->exit->img = mlx_xpm_file_to_image(vars->mlx, \
			EXIT, &data->exit->width, &data->exit->height);
	return (0);
}

int	map_print(t_mlx *vars, t_map *map, char *map_num)
{
	int		fd;
	char	*map_dir;

	if (map_num[0] == '1')
		map_dir = MAP_DIR_1;
	else if (map_num[0] == '2')
		map_dir = MAP_DIR_2;
	else if (map_num[0] == '3')
		map_dir = MAP_DIR_3;
	else if (map_num[0] == '4')
		map_dir = MAP_DIR_4;
	fd = open(map_dir, O_RDONLY);
	if (fd < 0)
		exit (1);
	while (1)
	{
		map_dir = get_next_line(fd);
		map_line(map_dir, vars, map);
		if (!map_dir)
			break ;
		free(map_dir);
	}
	close(fd);
	return (0);
}

int	map_line(char *line, t_mlx *vars, t_map *map)
{
	int			x;
	static int	y;

	x = 0;
	while (line)
	{
		if (*line == '0')
			map_put(vars, map->pass, x, y);
		else if (*line == '1')
			map_put(vars, map->wall, x, y);
		else if (*line == 'C')
			map_put(vars, map->collect, x, y);
		else if (*line == 'E')
			map_put(vars, map->exit, x, y);
		else if (*line == 'P')
			map_put(vars, map->starting, x, y);
		else if (*line == '\n' || *line == '\0')
			break ;
		else
			exit(1);
		x += 50;
		line++;
	}
	y += 50;
	return (0);
}
