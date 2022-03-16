/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver1.0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:16:12 by haryu             #+#    #+#             */
/*   Updated: 2022/03/17 01:43:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_intro(t_module *init)
{
	init->game.mlx_win = mlx_new_window(init->game.mlx, 400, 300, "SO_LONG");
	intro_load(&init->game, &init->intro);
	init->map_number = 0;
	init->sys_status = GAME_LOGO;
}

void	game_play(t_module *init, int map_num)
{
	char	map[2];

	map[0] = map_num + '0';
	map[1] = '\0';
	init->map_number = map_num;
	init->sys_status = GAME_PLAYING;
	mlx_destroy_window(init->game.mlx, init->game.mlx_win);
	map_checker(map, &init);
	init->game.mlx_win = mlx_new_window(init->game.mlx, init->map.position.x, init->map.position.y, "SO_LONG_ver.1.0.");
	map_load(&init->game, &init->map, map);
	mlx_key_hook(init->game.mlx_win, key_hook_switch, init);
	mlx_hook(init->game.mlx_win, 17, 1L<<3, press_close, init->game.mlx);
}

int main(void)
{
	t_module	*init;

	init = malloc(sizeof(t_module) * 1);
	if (!init)
		exit(1);
	init->game.mlx = mlx_init();
	game_intro(init);
	mlx_key_hook(init->game.mlx_win, key_hook_switch, &init);
	mlx_hook(init->game.mlx_win, 17, 1L<<3, press_close, &init->game);
	mlx_loop(init->game.mlx);
	return (0);

}
