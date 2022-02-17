/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:34:42 by haryu             #+#    #+#             */
/*   Updated: 2022/02/17 17:37:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_load(t_mlx *vars, t_map *data, char *map_num)
{
	data = malloc(sizeof(t_map) * 1);
	if (!data)
		return (-1);
	if(map_initialize(vars, data))
	{
		printf("error!\n");
		exit(1);
	}
	map_print(vars, data, map_num);
	return (0);
}

int map_initialize(t_mlx *vars, t_map *data)
{
	data->pass = malloc(sizeof(t_img) * 1);
	data->wall = malloc(sizeof(t_img) * 1);
	data->collect = malloc(sizeof(t_img) * 1);
	data->starting = malloc(sizeof(t_img) * 1);
	data->exit = malloc(sizeof(t_img) * 1);
	if (!(data->pass || data->wall || data->collect || data->starting || data->exit))
		return (1);
	data->pass->img = mlx_xpm_file_to_image(vars->mlx, PASS, &data->pass->width, &data->pass->height);
	data->wall->img = mlx_xpm_file_to_image(vars->mlx, WALL, &data->wall->width, &data->wall->height);
	data->collect->img = mlx_xpm_file_to_image(vars->mlx, COLLECT, &data->collect->width, &data->collect->height);
	data->starting->img = mlx_xpm_file_to_image(vars->mlx, STARTING, &data->starting->width, &data->starting->height);
	data->exit->img = mlx_xpm_file_to_image(vars->mlx, EXIT, &data->exit->width, &data->exit->height);
	map_get_addr(data->pass, data->wall, data->collect, data->starting, data->exit);

	return (0);	
}
void	map_get_addr(t_img *pass, t_img *wall, t_img *collect, t_img *starting, t_img *exit)
{
	pass->addr = mlx_get_data_addr\
				 (pass->img, &pass->bits_per_pixel, &pass->line_leng, &pass->endian);
	wall->addr = mlx_get_data_addr\
				 (wall->img, &wall->bits_per_pixel, &wall->line_leng, &wall->endian);
	collect->addr = mlx_get_data_addr\
					(collect->img, &collect->bits_per_pixel, &collect->line_leng, &collect->endian);
	starting->addr = mlx_get_data_addr\
					 (starting->img, &starting->bits_per_pixel, &starting->line_leng, &starting->endian);
	exit->addr = mlx_get_data_addr\
				 (exit->img, &exit->bits_per_pixel, &exit->line_leng, &exit->endian);
}

int	map_print(t_mlx *vars, t_map *map, char *map_num)
{
	int		fd;
	char	*map_dir;

	if (map_num[1] != '\0')
		exit (1);
	if (map_num[0] == '1')
		map_dir = MAP_DIR_1;
	else if (map_num[0] == '2')
		map_dir = MAP_DIR_2;
	else if (map_num[0] == '3')
		map_dir = MAP_DIR_3;
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
			map_put(vars->mlx, vars->mlx_win, map->pass, x, y);
		else if (*line == '1')
			map_put(vars->mlx, vars->mlx_win, map->wall, x, y);
		else if (*line == 'C')
			map_put(vars->mlx, vars->mlx_win, map->collect, x, y);
		else if (*line == 'E')
			map_put(vars->mlx, vars->mlx_win, map->exit, x, y);
		else if (*line == 'P')
			map_put(vars->mlx, vars->mlx_win, map->starting, x, y);
		else if (*line == '\n')
			break ;
		else
			exit(1);
		x += 50;
		line++;
	}
	y += 50;
	return (0);
}

int map_put(void *mlx, void *win, t_img *img, int x, int y)
{
	mlx_put_image_to_window(mlx, win, img->img, x, y);
	return (0);
}
