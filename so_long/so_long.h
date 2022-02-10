/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:43 by haryu             #+#    #+#             */
/*   Updated: 2022/02/11 00:16:20 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	make_square(t_mlx *window, t_data *data, int width, int height, int color);
void	make_circle(t_mlx *window, t_data *data, int radius, int color);
void	make_square_full(t_mlx *window, t_data *data, int width, int height, int color);

#endif
