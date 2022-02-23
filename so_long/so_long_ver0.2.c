/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ver0.2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:58:22 by haryu             #+#    #+#             */
/*   Updated: 2022/02/24 00:26:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_main(t_module **init)
{
	(*init)->vars.mlx_win = mlx_new_window((*init)->vars.mlx, 400, 300, "Intro");
	intro_load(&(*init)->vars, &(*init)->intro);
	(*init)->system = 0;
}

void	game_map(t_module **init, int map_num)
{
	char	*map;

	map = mapnum_out(map_num);
	(*init)->system = 3;
	mlx_destroy_window((*init)->vars.mlx, (*init)->vars.mlx_win);
	map_checker(map, &(*init)->map.x, &(*init)->map.y);
	(*init)->vars.mlx_win = mlx_new_window((*init)->vars.mlx, (*init)->map.x, (*init)->map.y, "SO_LONG");
	map_load(&(*init)->vars, &(*init)->map, map);
	(*init)->enemies = malloc(sizeof(t_enemy) * 1);
	enemy_load(&(*init)->vars, (*init)->enemies);
	mlx_key_hook((*init)->vars.mlx_win, key_hook_switch, &(*init));
	mlx_hook((*init)->vars.mlx_win, 17, 1L<<3, press_close, &(*init)->vars);
}

void	game_last(t_module **init);

int main(void)
{
	t_module	*init;

	init = malloc(sizeof(t_module) * 1);
	if (!init)
		exit(1);
	init->vars.mlx = mlx_init();
	game_main(&init);
	mlx_key_hook(init->vars.mlx_win, key_hook_switch, &init);
	mlx_hook(init->vars.mlx_win, 17, 1L<<3, press_close, &init->vars);
	mlx_loop(init->vars.mlx);
	return (0);
}