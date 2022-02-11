/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:43 by haryu             #+#    #+#             */
/*   Updated: 2022/02/11 21:02:05 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//header
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

//should be deleted
# include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_leng;
	int		endian;
}				t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

//usefull_functs
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// colors
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		add_shade(double shader, int trgb);
int		get_opposite(int trgb);

//testcase_functs
void	make_square(t_mlx *window, t_data *data, int width, int height, int color);
void	make_circle(t_mlx *window, t_data *data, int radius, int color);
void	make_square_full(t_mlx *window, t_data *data, int width, int height, int color);

#endif
