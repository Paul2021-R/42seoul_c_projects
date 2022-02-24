/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_intro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:31:01 by haryu             #+#    #+#             */
/*   Updated: 2022/02/23 21:38:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int intro_load(t_mlx *vars, t_intro *data)
{
	int i;
	int keycode;

	if (intro_initialize(vars, data))
	{
		printf("error\n");
		exit(1);
	}
	intro_print(vars, data, 0);

	return (0);
}

int intro_initialize(t_mlx *vars, t_intro *intro)
{
	intro->logo = malloc(sizeof(t_img) * 1);
	intro->intro_1 = malloc(sizeof(t_img) * 1);
	intro->intro_2 = malloc(sizeof(t_img) * 1);
	intro->gameover = malloc(sizeof(t_img) * 1);
	intro->gameclear = malloc(sizeof(t_img) * 1);
	intro->logo->img = mlx_xpm_file_to_image(vars->mlx, LOGO, &intro->logo->width, &intro->logo->height);
	intro->intro_1->img = mlx_xpm_file_to_image(vars->mlx, MAIN_1, &intro->intro_1->width, &intro->intro_1->height);
	intro->intro_2->img = mlx_xpm_file_to_image(vars->mlx, MAIN_2, &intro->intro_2->width, &intro->intro_2->height);
	intro->gameover->img = mlx_xpm_file_to_image(vars->mlx, OVER, &intro->gameover->width, &intro->gameover->height);
	intro->gameclear->img = mlx_xpm_file_to_image(vars->mlx, CLEAR, &intro->gameclear->width, &intro->gameclear->height);
	return (0);
}

int	intro_print(t_mlx *vars, t_intro *intro, int keycode)
{
	if (keycode == 0)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, intro->logo->img, 0, 0);
	else if (keycode == 1)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, intro->intro_1->img, 0, 0);
	else if (keycode == 2)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, intro->intro_2->img, 0, 0);
	else if (keycode == 3)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, intro->gameclear->img, 0, 0);
	else if (keycode == 4)
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, intro->gameover->img, 0, 0);
	return (0);
}
