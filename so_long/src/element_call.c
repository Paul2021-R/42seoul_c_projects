/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_call.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:51:34 by haryu             #+#    #+#             */
/*   Updated: 2022/03/23 23:04:02 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void element_put(t_mlx *vars, t_img *img, int x, int y)
{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, x, y);
}

int	elements_call(t_module *init)
{
	player_load(init);
	coin_load(init);
	return (0);
}

void	p_image_load(t_img *sprite, t_mlx *vars)
{
	int	width;
	int	height;

	sprite->img = mlx_xpm_file_to_image(vars->mlx, P_RIGHT, &sprite->width, &sprite->height);
}

void	c_image_load(t_img *sprite, t_mlx *vars)
{
	int	width;
	int	height;

	sprite->img = mlx_xpm_file_to_image(vars->mlx, COIN, &sprite->width, &sprite->height);
}

int	graphic_init(t_module *init, char code)
{
	if (code == 'P')
		p_image_load(init->player.sprite, &init->game);
	else if (code == 'C')
		c_image_load(init->coin, &init->game);
	return (0);
}
// enemy 숫자 맞춰서 호출 해야함
