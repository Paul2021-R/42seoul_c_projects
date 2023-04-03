/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:37:04 by haryu             #+#    #+#             */
/*   Updated: 2022/02/11 22:18:41 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_mlx	window;
	t_data	img;
	int		color;
	int		i;

	color = create_trgb(0, 0, 0, 127);
	printf("normal color : %x\n", color);
	color = add_shade(0.5, color);
	printf("shader changed : %d\n", color);
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 1200, 800, "My Color Practice!!");
	img.img = mlx_new_image(window.mlx, 1200, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_leng, &img.endian);
	i = 0;
	while(i < 100)
	{
		my_mlx_pixel_put(&img, 10, i, color);
		mlx_put_image_to_window(window.mlx, window.mlx_win, img.img, 10, i);
		i++;
	}
	i = 0;
	color = get_opposite(color);
	while(i < 100)
	{
		my_mlx_pixel_put(&img, 100, i, color);
		mlx_put_image_to_window(window.mlx, window.mlx_win, img.img, 100, i);
		i++;
	}
	//make_square_full(&window, &img, 100, 100, color);
	mlx_loop(window.mlx);
}
