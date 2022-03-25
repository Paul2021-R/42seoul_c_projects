/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_call_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:51:34 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 22:54:00 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/so_long_bonus.h"

void	element_put(t_mlx *vars, t_img *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, x, y);
}

int	elements_call(t_module *init)
{
	player_load(init);
	coin_load(init);
	return (0);
}

void	p_image_load(t_img *sprite, t_mlx *vars, int arrow)
{
	int		i;
	char	*dir;

	dir = print_directory(arrow);
	sprite[0].img = mlx_xpm_file_to_image(vars->mlx, \
	P_DEFAULT, &sprite[0].width, &sprite[0].height);
	sprite[1].img = mlx_xpm_file_to_image(vars->mlx, \
	ft_strjoin(P_SEMI, dir), &sprite[1].width, &sprite[1].height);
	sprite[2].img = mlx_xpm_file_to_image(vars->mlx, \
	ft_strjoin(P_OPEN, dir), &sprite[2].width, &sprite[2].height);
}

void	c_image_load(t_img *sprite, t_mlx *vars)
{
	sprite->img = mlx_xpm_file_to_image(vars->mlx, \
	COIN, &sprite->width, &sprite->height);
	if (sprite->img == NULL)
	{
		printf("<sys>\nPlayer file load is failed\n");
		exit(1);
	}
}
