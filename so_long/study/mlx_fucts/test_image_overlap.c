/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_image_overlap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:02:41 by haryu             #+#    #+#             */
/*   Updated: 2022/03/23 18:20:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(void)
{
	t_module	*init;
	int			width;
	int			height;
	void		*current_1;
	void		*current_2;

	init = malloc(sizeof(t_module) * 1);
	init->game.mlx = mlx_init();
	init->game.mlx_win = mlx_new_window(init->game.mlx, 400, 300, "Test");
	init->intro.logo = malloc(sizeof(t_img) * 1);
	init->player.sprite = malloc(sizeof(t_img) * 1);
	init->intro.logo->img = mlx_xpm_file_to_image(init->game.mlx, LOGO, &width, &height);
	init->player.sprite->img = mlx_xpm_file_to_image(init->game.mlx, P_RIGHT, &width, &height);
	mlx_put_image_to_window(init->game.mlx, init->game.mlx_win, init->intro.logo->img, 0, 0);
	mlx_put_image_to_window(init->game.mlx, init->game.mlx_win, init->player.sprite->img, 150, 200);
	mlx_loop(init->game.mlx);
}