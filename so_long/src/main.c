/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:48:39 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 16:44:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mandatory/so_long.h"

void	game_intro(t_module *init, int status)
{
	init->game.mlx_win = mlx_new_window(init->game.mlx, \
	400, 300, "SO_LONG_ver.1.3.");
	if (status == GAME_LOGO)
	{
		intro_load(init);
		init->map_number = 0;
		init->sys_status = GAME_LOGO;
	}
	else
	{
		init->sys_status = status;
		intro_print(&init->game, &init->intro, status);
	}
	mlx_key_hook(init->game.mlx_win, key_hook_switch, init);
	mlx_hook(init->game.mlx_win, 17, 0, press_close, init->game.mlx);
}

void	game_play(t_module *init, int map_num)
{
	char	map[2];

	map[0] = map_num + '0';
	map[1] = '\0';
	init->map_number = map_num;
	init->sys_status = GAME_PLAYING;
	mlx_destroy_window(init->game.mlx, init->game.mlx_win);
	printf("<sys>\nCurrent game status is [%d].\n", GAME_PLAYING);
	map_checker(map, &init);
	init->game.mlx_win = mlx_new_window(init->game.mlx, \
	init->map.position.x, init->map.position.y, "SO_LONG_ver.1.3.");
	map_load(&init->game, &init->map, map);
	elements_call(init);
	mlx_key_hook(init->game.mlx_win, key_hook_switch, init);
	mlx_hook(init->game.mlx_win, 17, 0, press_close, init->game.mlx);
}

int	main(void)
{
	t_module	*init;

	init = malloc(sizeof(t_module) * 1);
	if (!init)
		exit(1);
	init->game.mlx = mlx_init();
	game_intro(init, GAME_LOGO);
	mlx_key_hook(init->game.mlx_win, key_hook_switch, init);
	mlx_hook(init->game.mlx_win, 17, 0, press_close, &init->game);
	mlx_loop(init->game.mlx);
	return (0);
}
