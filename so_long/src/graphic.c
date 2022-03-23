/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:08:47 by haryu             #+#    #+#             */
/*   Updated: 2022/03/23 18:27:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	p_image_load(t_img *sprite, t_mlx *vars)
{
	int	width;
	int	height;

	sprite->img = mlx_xpm_file_to_image(vars->mlx, P_RIGHT, &sprite->width, &sprite->height);
}

int	c_image_load(t_img *sprite, t_mlx *vars)
{
	return (0);
}

int	graphic_init(t_module *init, char code)
{
	if (code == 'P')
		p_image_load(init->player.sprite, &init->game);

	else if (code == 'C')
		// c_image_load(init->coin, vars);
	return (0);
}