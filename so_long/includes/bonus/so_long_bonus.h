/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:43 by haryu             #+#    #+#             */
/*   Updated: 2022/03/26 00:37:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// header
# include "../../library/mlx/mlx.h"
# include "../../library/libft/libft.h"
# include "../../library/gnl/get_next_line.h"
# include "meta_data_bonus.h"
# include "map_bonus.h"
# include "element_bonus.h"
# include <sys/time.h>

typedef struct s_module
{
	t_mlx		game;
	t_intro		intro;
	t_map		map;
	int			map_number;
	int			sys_status;
	t_player	player;
	t_img		*coin;
	t_position	starting;
	t_position	exit;
}				t_module;

typedef struct s_frame
{
	struct timeval	tv;
	struct timeval	tv2;
}				t_frame;

// game main menu
void
game_intro(t_module *init, int status);
int		intro_load(t_module *init);
int		intro_malloc(t_intro *intro);
int		intro_initialize(t_mlx *game, t_intro *intro);
int		intro_print(t_mlx *game, t_intro *intro, int game_status);

// map load & image print
void	game_play(t_module *init, int map_num);
void	map_save(t_map *map, char *line, int y);
int		map_load(t_mlx *game, t_map *data, char *map_num);
int		map_initialize(t_mlx *vars, t_map *data);
int		map_print(t_mlx *vars, t_map *map, char *map_num);
int		map_line(char *line, t_mlx *vars, t_map *map);
int		map_checker(char *map, t_module **init);
int		map_resolution(char *map, \
t_module **init, unsigned int *x, unsigned int *y);

// element load & image print
int		elements_call(t_module *init);
void	element_put(t_mlx *vars, t_img *img, int x, int y);
int		player_load(t_module *init);
int		player_initialize(t_player *me, t_module *init);
int		player_position_init(t_position *position, t_module *init);
int		check_x_y(char **map, unsigned int *x, unsigned int *y, char checker);
void	p_image_load(t_img *sprite, t_mlx *vars, int arrow);
void	c_image_load(t_img *sprite, t_mlx *vars);
int		coin_load(t_module *init);

// map error check
int		map_error(int fd, t_rule *rules, \
unsigned int *width, unsigned int *height);
void	find_target(char *str, t_rule *target);
void	initialize_rules(t_rule *rules);
int		width_check(unsigned int height, \
unsigned int width, unsigned int current);
int		wall_check(char *str, int height, int width, int *open);
void	error_noti(t_module **init);
void	check_img_pointer_intro(t_intro *intro);
void	malloc_error(char *str);

// hook & events
int		key_hook_switch(int kecode, t_module *init);
int		key_hook_switch_2(int kecode, t_module *init);
int		mlx_close(t_mlx *vars);
int		press_close(t_mlx *vars);
void	press_move_key(int keycode, t_module *init);
int		status_control(int keycode, t_module *init, int game_status);

int		move(int arrow, t_module *init);
int		check_move_ok(char **map, unsigned int *x, unsigned int *y, int arrow);
void	player_switch_put(t_module *init, t_position old, int arrow, int i);
t_img	*choose_direction(t_player *player, int arrow);
void	player_move_put(t_module *init, t_player *player, int arrow);

// utills
char	*mapnum_out(int map_num);
void	print_current_system(t_module *init);
char	*print_directory(int arrow);
void	*frame_init(int *value, int arrow);
#endif
