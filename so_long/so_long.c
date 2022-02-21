/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:58:22 by haryu             #+#    #+#             */
/*   Updated: 2022/02/21 22:53:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_module	*init;
	int			x;
	int			y;	

	if (ac != 2)
		return (0);
	init = malloc(sizeof(t_module) * 1);
	if (!init)
		exit(1);
	init->vars.mlx = mlx_init();
	map_checker(av[1], &x, &y);
	init->vars.mlx_win = mlx_new_window(init->vars.mlx, x, y, "map test");
	map_load(&init->vars, init->map, av[1]);
	mlx_key_hook(init->vars.mlx_win, key_hook_switch, &init->vars);
	mlx_hook(init->vars.mlx_win, 17, 1L<<3, press_close, &init->vars);
	mlx_loop(init->vars.mlx);
	return (0);
}
