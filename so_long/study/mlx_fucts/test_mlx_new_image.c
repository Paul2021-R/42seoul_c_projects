/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx_new_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:03:04 by haryu             #+#    #+#             */
/*   Updated: 2022/02/11 00:33:22 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_mlx	window;
	void	*mlx_win;
	t_data	img;

	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, 1024, 768, "My Practice!!");
	img.img = mlx_new_image(window.mlx, 1024, 768);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_leng, &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//도트 찍기
	make_square(&window, &img, 100, 100, 0x00FF0000);
	//make_square_full(&window, &img, 100, 100, 0x00FF0000);
	//사각형 테스트
	make_circle(&window, &img, 50, 0x00FF0000);
	//원형 테스트
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//실제 찍는 함수
	mlx_loop(window.mlx);
}
