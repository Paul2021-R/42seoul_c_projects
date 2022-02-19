/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:43 by haryu             #+#    #+#             */
/*   Updated: 2022/02/20 00:33:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//header
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>

// defines

# define WALL "./asset/map/wall_xpm.xpm"
# define PASS "./asset/map/pass_xpm.xpm"
# define COLLECT "./asset/map/collect_xpm.xpm"
# define STARTING "./asset/map/starting_xpm.xpm"
# define EXIT "./asset/map/exit_xpm.xpm"
# define MAP_DIR_1 "./asset/ber/map_1.ber"
# define MAP_DIR_2 "./asset/ber/map_2.ber"
# define MAP_DIR_3 "./asset/ber/map_3.ber"
# define MAP_DIR_4 "./asset/ber/custom.ber"

//module
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_leng;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_map
{
	t_img	*pass;
	t_img	*wall;
	t_img	*collect;
	t_img	*exit;
	t_img	*starting;
}				t_map;

typedef struct s_module
{
	t_mlx	vars;
	t_map	*map;	
}				t_module;

typedef struct s_rule
{
	int		starting;
	int		collect;
	int		exit;
}				t_rule;

// map load & print

int		map_load(t_mlx *vars, t_map *data, char *map_num);
int		map_initialize(t_mlx *vars, t_map *data);
void	map_get_addr(t_img *pass, t_img *wall, t_img *collect, t_img *starting, t_img *exit);
int 	map_print(t_mlx *vars, t_map *map, char *map_num);
int		map_line(char *line, t_mlx *vars, t_map *map);
int		map_put(void *mlx, void *win, t_img *img, int x, int y);
int		map_checker(char *map, int *x, int *y);
int		map_resolution(char *map, int *x, int *y);

//map error check

int		map_error(int fd, int *width, int *height);
void	find_target(char *str, t_rule *target);
void	initialize_rules(t_rule *rules);
int		width_check(int height, int width, int current);
int		wall_check(char *str, int height, int width, int *open);

//usefull_functs
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// colors
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		add_shade(double shader, int trgb);
int		get_opposite(int trgb);

// hook & events 
int		key_hook_switch(int kecode, t_mlx *vars);
int		mlx_close(int keycode, t_mlx *vars);
int		window_resizing(t_mlx *mlx);
int		press_close(void);
int		buttons_press(int button, int x, int y, t_mlx *vars);
int 	mouse_inout(int x, int y, t_mlx *vars);
void	press_move_key(int keycode);
int		mouse_scroll(int button, int x, int y, t_mlx *vars);
int		mouse_scroll_down(int button, int x, int y, t_mlx *vars);
int		mouse_angle(int button, int x, int y, t_mlx *vars);

// loops 
int		render_next_frame(void *yourstruct);

//testcase_functs
//void	make_square(t_mlx *window, t_data *data, int width, int height, int color);
//void	make_circle(t_mlx *window, t_data *data, int radius, int color);
//void	make_square_full(t_mlx *window, t_data *data, int width, int height, int color);

#endif
