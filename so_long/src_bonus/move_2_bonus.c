/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:08:18 by haryu             #+#    #+#             */
/*   Updated: 2022/03/26 00:39:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/so_long_bonus.h"

t_img	*choose_direction(t_player *player, int arrow)
{
	t_img	*ret;

	if (arrow == UP)
		ret = player->sprite_up;
	else if (arrow == DOWN)
		ret = player->sprite_down;
	else if (arrow == LEFT)
		ret = player->sprite_left;
	else
		ret = player->sprite_right;
	return (ret);
}

void	player_move_put(t_module *init, t_player *player, int arrow)
{
	int	x[3];
	int	y[3];

	frame_init(x, 0);
	frame_init(y, 0);
	if (arrow == UP || arrow == DOWN)
		frame_init(y, arrow);
	else
		frame_init(x, arrow);
}
