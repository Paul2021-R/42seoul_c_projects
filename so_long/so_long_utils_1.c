/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:31:18 by haryu             #+#    #+#             */
/*   Updated: 2022/02/13 13:41:25 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * 기본 윈도우 생성, 도형 렌더링 관련 함수 
 */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_leng + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	make_square(t_mlx *window, t_data *data, int width, int height, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (width <= 0 || height <= 0)
	{
		printf("erro가 발생하였습니다.");
		exit(1);
	}
	while (x < width)
	{
		my_mlx_pixel_put(data, x, 0, color);
		mlx_put_image_to_window(window->mlx, window->mlx_win, data->img, 10, 10);
		my_mlx_pixel_put(data, x, height - 1, color);
		mlx_put_image_to_window(window->mlx, window->mlx_win, data->img, 10, 10);
		x++;
	}
	while (y < height)
	{
		my_mlx_pixel_put(data, 0, y, color);
		mlx_put_image_to_window(window->mlx, window->mlx_win, data->img, 10, 10);
		my_mlx_pixel_put(data, width - 1, y, color);
		mlx_put_image_to_window(window->mlx, window->mlx_win, data->img, 10, 10);

		y++;
	}

}

void	make_circle(t_mlx *window, t_data *data, int radius, int color)
{
	int i;
	int j;
	int r;
	int hr;
	int dr;

	r = radius;
	radius = r * 2;
	dr = r * r;
	i = 0;
	hr = 0.5 - r;
	while (i < radius)
	{
		j = 0;
		while (j < radius)
		{
			if (dr > (i + hr) * (i + hr) + (j + hr) * (j + hr))
			{
				my_mlx_pixel_put(data, j, i, color);
				mlx_put_image_to_window(window->mlx, window->mlx_win, data->img, 120, 120);
			}
			j++;
		}
		color += 1;
		i++;
	}
}

void	make_square_full(t_mlx *window, t_data *data, int width, int height, int color)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (width <= 0 || height <= 0)
	{
		printf("erro가 발생하였습니다.");
		exit(1);
	}
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			my_mlx_pixel_put(data, x, y, color);
			mlx_put_image_to_window(window->mlx, window->mlx_win, data->img, 0, 0);
			y++;
		}
		//color++;
		x++;
	}
}
