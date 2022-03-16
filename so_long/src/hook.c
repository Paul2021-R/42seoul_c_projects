/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:16:50 by haryu             #+#    #+#           :q  */
/*   Updated: 2022/03/16 16:49:09 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	press_move_key(int keycode)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		printf("up\n");
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		printf("down\n");
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		printf("left\n");
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		printf("right\n");
	return ;
}

int	mlx_close(int keycode, t_mlx *vars)
{
	printf("So_long is turned off.\n");
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit (0);
}

int press_close(t_mlx *vars)
{
	printf("Pressed 'X' button. So_long is turned off.\n");
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit (0);
}

int	key_hook_switch(int keycode, t_module **init)
{
	if (keycode == KEY_W || keycode == KEY_A \
			|| keycode == KEY_S || keycode == KEY_D \
			|| (keycode >= KEY_LEFT && keycode <= KEY_UP))
		press_move_key(keycode);
	else if (keycode == KEY_ENTER && (*init)->sys_status == GAME_LOGO)
	{
		(*init)->sys_status = GAME_MAIN_1;
		intro_print(&(*init)->game, &(*init)->intro, GAME_MAIN_1);
	}
	else if ((keycode == KEY_ENTER || keycode == 83 || keycode == KEY_1) && (*init)->sys_status == GAME_MAIN_1)
	{
		(*init)->sys_status = GAME_MAIN_2;
		intro_print(&(*init)->game, &(*init)->intro, GAME_MAIN_2);
	}
	else if (keycode == 53 || ((keycode == KEY_2 || keycode == 84) && (*init)->sys_status == GAME_MAIN_1))
		mlx_close(keycode, &(*init)->game);
	else if ((keycode == 51 && (*init)->sys_status == GAME_MAIN_2))
	{
		(*init)->sys_status--;
		intro_print(&(*init)->game, &(*init)->intro, 1);	
	}
	else if (keycode > 17 && keycode < 22 && (*init)->sys_status == GAME_MAIN_2)
		game_map(init, keycode);
	else if (keycode == 35)
		print_current_system(init);
	else
		printf("%d\n",keycode);
	return (0);
}
