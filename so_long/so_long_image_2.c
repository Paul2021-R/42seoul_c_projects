/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:45:24 by haryu             #+#    #+#             */
/*   Updated: 2022/02/17 20:07:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_put(void *mlx, void *win, t_img *img, int x, int y)
{
	mlx_put_image_to_window(mlx, win, img->img, x, y);
	return (0);
}

int	map_checker(char *map, int *x, int *y)
{
	if (map[0] == '1')
		map_resolution(MAP_DIR_1, x, y);	
	else if (map[0] == '2')
		map_resolution(MAP_DIR_2, x, y);
	else if (map[0] == '3')
		map_resolution(MAP_DIR_3, x, y);
	else if (map[0] == '4')
		map_resolution(MAP_DIR_4, x, y);
	else
		exit (0);
	return (0);
}

int	map_resolution(char *map, int *x, int *y)
{
	int		fd;
	int		width;
	int		height;
	char	*map_dir;

	map_dir = map;
	fd = open(map_dir, O_RDONLY);
   	if (fd < 0)
		exit (1);
	height = 0;
	width = 0;
	while(1)
	{
		map_dir = get_next_line(fd);
		if (!map_dir)
			break ;
		width = (int)ft_strlen(map_dir);
		free (map_dir);
		height += 1;
	}
	*x = 50 * (width - 1);
	*y = 50 * height;
	close(fd);
	return (0);
}
