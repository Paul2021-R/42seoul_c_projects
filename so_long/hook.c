/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:16:50 by haryu             #+#    #+#           :q  */
/*   Updated: 2022/02/24 15:45:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_move_key(int keycode)
{
	if (keycode == 13 || keycode == 126)
		printf("up\n");
	else if (keycode == 1 || keycode == 125)
		printf("down\n");
	else if (keycode == 0 || keycode == 123)
		printf("left\n");
	else if (keycode == 2 || keycode == 124)
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
	if (keycode == 13 || keycode == 0 \
			|| keycode == 1 || keycode == 2 \
			|| (keycode >= 123 && keycode <= 126))
		press_move_key(keycode);
	else if (keycode == 36 && (*init)->system == 0)
	{
		(*init)->system = 1;
		intro_print(&(*init)->vars, &(*init)->intro, 1);
	}
	else if ((keycode == 36 || keycode == 83 || keycode == 18) && (*init)->system == 1)
	{
		(*init)->system = 2;
		intro_print(&(*init)->vars, &(*init)->intro, 2);
	}
	else if (keycode == 53 || ((keycode == 19 || keycode == 84) && (*init)->system == 1))
		mlx_close(keycode, &(*init)->vars);
	else if ((keycode == 51 && (*init)->system == 2))
	{
		(*init)->system--;
		intro_print(&(*init)->vars, &(*init)->intro, 1);	
	}
	else if (keycode > 17 && keycode < 22 && (*init)->system == 2)
		game_map(init, keycode);
	else if (keycode == 35)
		print_current_system(init);
	else
		printf("%d\n",keycode);
	return (0);
}

// 해야할 키구현 
// esc 누를시 종료 
// 방향키 누를 시 움직임 
// 엔터 누를 시 확인(필요 할까?)
//
