/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:16:21 by haryu             #+#    #+#             */
/*   Updated: 2022/02/16 22:50:35 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_mlx	mlx;
	t_data	img;
	char 	*relative_path = "./source/src_img/player_xpm.xpm";
	int		img_width;
	int		img_height;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1024, 768, "test_images");
	print_map("110011PEC00\n11100011100CC0011", &mlx);
	mlx_loop(mlx.mlx);
}
