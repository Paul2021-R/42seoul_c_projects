/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:52:47 by haryu             #+#    #+#             */
/*   Updated: 2022/03/24 00:55:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook_switch_2(int keycode, t_module *init)
{
	if (keycode == KEY_1)
	{
		game_play(init, init->map_number);
	}
	if (keycode == KEY_2)
	{
		init->sys_status = GAME_MAIN_1;
		intro_print(&init->game, &init->intro, init->sys_status);
	}
	if (keycode == KEY_3)
		mlx_close(keycode, &init->game);
	return (0);
}