/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:16:50 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 16:08:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	press_move_key(int keycode, t_module *init)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		move(UP, init);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(DOWN, init);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(LEFT, init);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(RIGHT, init);
	return ;
}

int	mlx_close(t_mlx *vars)
{
	printf("<sys>\nSo_long is turned off properly.\n");
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

int	press_close(t_mlx *vars)
{
	printf("<sys>\nYou pressed 'X' button.\nSo_long is turned off properly.\n");
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
}

int	status_control(int keycode, t_module *init, int game_status)
{
	if (game_status == GAME_LOGO && keycode == KEY_ENTER)
	{
		init->sys_status = GAME_MAIN_1;
		intro_print(&init->game, &init->intro, init->sys_status);
	}
	else if (game_status == GAME_MAIN_1 && keycode == KEY_2)
		mlx_close(&init->game);
	else if (game_status == GAME_MAIN_1 && \
	(keycode == KEY_ENTER || keycode == KEY_1))
	{
		init->sys_status = GAME_MAIN_2;
		intro_print(&init->game, &init->intro, init->sys_status);
	}
	else if (game_status == GAME_MAIN_2 && (keycode > 17 && keycode < 22))
		game_play(init, keycode - 17);
	return (0);
}

int	key_hook_switch(int keycode, t_module *init)
{
	if ((init->sys_status != GAME_PLAYING))
		status_control(keycode, init, init->sys_status);
	if (keycode == KEY_ESC)
		mlx_close(&init->game);
	if (keycode == KEY_W || keycode == KEY_A || \
	keycode == KEY_S || keycode == KEY_D || \
	(keycode >= KEY_LEFT && keycode <= KEY_UP))
	{
		if (init->sys_status == GAME_PLAYING)
			press_move_key(keycode, init);
	}
	else if ((keycode == KEY_BACK && init->sys_status == GAME_MAIN_2))
	{
		init->sys_status = GAME_MAIN_1;
		intro_print(&init->game, &init->intro, 1);
	}
	else if (keycode == KEY_P)
		print_current_system(init);
	else if (init->sys_status == GAME_CLEAR || init->sys_status == GAME_OVER)
		key_hook_switch_2(keycode, init);
	return (0);
}
