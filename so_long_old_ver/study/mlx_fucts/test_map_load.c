/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:58:22 by haryu             #+#    #+#             */
/*   Updated: 2022/02/17 18:50:32 by haryu            ###   ########.fr       */
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
	mlx_loop(init->vars.mlx);
	return (0);
}
