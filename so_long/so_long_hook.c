/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:41:43 by haryu             #+#    #+#             */
/*   Updated: 2022/02/13 19:12:35 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int mlx_close(int keycode, t_mlx *vars)
{
	if (keycode == 53)
	{
		printf("you pressed ESC\n");
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	printf("you didn't press ESC\n");
	return (0);
}

int key_hook_switch(int keycode, t_mlx *vars)
{
	if (keycode == 53)
		mlx_close(keycode, vars);
	else if (keycode == 44)
	{
		printf("도움말 보기를 실행합니다.\n");
		return (0);
	}
	else if (keycode == 13 || keycode == 0 \
			|| keycode == 1 || keycode == 2\
			|| (keycode >= 123 && keycode <= 126))
		press_move_key(keycode);
	//printf("당신은 %d 키를 누르셨습니다.\n", keycode);
	return (0);
}

void press_move_key(int keycode)
{
	if (keycode == 13 || keycode == 126)
	{
		printf("up key를 누르셨습니다.\n");
	}
	else if (keycode == 1 || keycode == 125)
	{
		printf("down key를 누르셨습니다.\n");
	}
	else if (keycode == 0 || keycode == 123)
	{
		printf("left key를 누르셨습니다.\n");
	}
	else if (keycode == 2 || keycode == 124)
	{
		printf("right key를 누르셨습니다.\n");
	}
}

int window_resizing(t_mlx *mlx)
{
	printf("resizing check\n");
	return (0);
}

int buttons_press(int button, int x, int y, t_mlx *vars)
{
	printf("You pressed\nx=[%d], y=[%d]\nbutton=[%d]\n", x, y, button);
	return (0);
}

int	mouse_inout(int x, int y, t_mlx *vars)
{
	if ((x <= 1024 && x > 0) && (y <= 768 && y > 0))
	{
		printf("your mouse cursor in the window.\n");
		printf("x = %d, y = %d\n", x, y);
	}
	else if ((x < 0 || x > 1024) || (y < 0 || y > 768))
	{
		printf("your mouse cursor is out of the window.\n");
		printf("x = %d, y = %d\n", x, y);
	}
	return (0);
}
