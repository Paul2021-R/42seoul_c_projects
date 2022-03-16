/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver1.0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:16:12 by haryu             #+#    #+#             */
/*   Updated: 2022/03/16 14:58:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_main(t_module *init)
{
	init->game.mlx_win = mlx_new_window(init->game.mlx, 400, 300, "SO_LONG");
	intro_load(&init->game, &init->intro);
	init->map_number = 0;
	init->sys_status = GAME_LOGO;
}

int main(void)
{
	t_module	*init;

	init = malloc(sizeof(t_module) * 1);
	init->game.mlx = mlx_init();
	game_main(&init);

}
