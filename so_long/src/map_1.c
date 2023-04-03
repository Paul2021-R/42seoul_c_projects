/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:34:42 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 16:44:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mandatory/so_long.h"

int	map_load(t_mlx *game, t_map *data, char *map_num)
{
	if (map_initialize(game, data))
	{
		printf("<sys>\nMap initialization is failed\nError!\n");
		exit(1);
	}
	map_print(game, data, map_num);
	return (0);
}

int	map_initialize(t_mlx *vars, t_map *data)
{
	data->pass = malloc(sizeof(t_img) * 1);
	data->wall = malloc(sizeof(t_img) * 1);
	data->exit = malloc(sizeof(t_img) * 1);
	if (!(data->pass || data->wall || \
	data->starting || data->exit))
		return (1);
	data->pass->img = mlx_xpm_file_to_image(vars->mlx, \
	PASS, &data->pass->width, &data->pass->height);
	data->wall->img = mlx_xpm_file_to_image(vars->mlx, \
	WALL, &data->wall->width, &data->wall->height);
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
		exit(1);
	while (1)
	{
		map_dir = get_next_line(fd);
		if (!map_dir)
			break ;
		map_line(map_dir, vars, map);
	}
	close(fd);
	return (0);
}

int	map_line(char *line, t_mlx *game, t_map *map)
{
	int			x;
	static int	y;

	x = 0;
	map_save(map, line, y);
	while (line)
	{
		if (*line == '0' || *line == 'C')
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			map->pass->img, x, y);
		else if (*line == '1')
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			map->wall->img, x, y);
		else if (*line == 'E' || *line == 'P')
			mlx_put_image_to_window(game->mlx, game->mlx_win, \
			map->exit->img, x, y);
		else if (*line == '\n' || *line == '\0')
			break ;
		x += SIZE;
		line++;
	}
	y += SIZE;
	if (y == (int)map->position.y)
		y = 0;
	return (0);
}

void	map_save(t_map *map, char *line, int y)
{
	if (ft_strlen(line) == 0)
		return ;
	if (y == 0)
	{
		map->rule.map_data = malloc(sizeof(char *) * (map->position.y / SIZE));
		if (!map->rule.map_data)
		{
			printf("<sys>\nMap Data saving is failed.\nError\n");
			exit(1);
		}
	}
	if (y == 0)
		map->rule.map_data[0] = ft_strdup(line);
	else
		map->rule.map_data[y / SIZE] = ft_strdup(line);
	if (map->rule.map_data[y / SIZE] == NULL)
	{
		printf("<sys>\nMap data passing is failed.\nError\n");
		exit(1);
	}
	return ;
}
