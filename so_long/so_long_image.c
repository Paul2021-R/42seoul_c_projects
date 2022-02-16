/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:34:42 by haryu             #+#    #+#             */
/*   Updated: 2022/02/16 22:59:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_map(char *map, t_mlx *mlx)
{
	t_data		img;
	int			img_w;
	int			img_h;
	int			i;
	int			x;
	int			y;

	i = -1;
	x = 0;
	y = 0;
	while (map[++i])
	{
		if (map[i] == '1')
			img.img = mlx_xpm_file_to_image(mlx->mlx, "./source/src_img/wall_xpm.xpm", &img_w, &img_h);
		else if(map[i] == '0')
			img.img = mlx_xpm_file_to_image(mlx->mlx, "./source/src_img/pass_xpm.xpm", &img_w, &img_h);
		else if(map[i] == 'E')
			img.img = mlx_xpm_file_to_image(mlx->mlx, "./source/src_img/wall_xpm.xpm",&img_w, &img_h);
		else if(map[i] == 'C')
			img.img = mlx_xpm_file_to_image(mlx->mlx, "./source/src_img/collet_xpm.xpm", &img_w, &img_h);
		else if(map[i] == 'P')
			img.img = mlx_xpm_file_to_image(mlx->mlx, "./source/src_img/player_xpm.xpm", &img_w, &img_h);
		else if(map[i] == '\n')
		{
			x = 0;
			y += 50;
		}
		else
			return (-1);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_leng, &img.endian);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img.img, x, y);
		x += 50;
	}
	return (0);
}
