/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx_loops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:41:45 by haryu             #+#    #+#             */
/*   Updated: 2022/02/16 21:56:48 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_mlx vars;
	t_data img;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1024, 768, "loops testing!");
	img.img = mlx_new_image(vars.mlx, 1024, 768);
//	mlx_loop_hook(vars.mlx, render_next_frame, &img);
	mlx_loop(vars.mlx);
	return (0);
}
