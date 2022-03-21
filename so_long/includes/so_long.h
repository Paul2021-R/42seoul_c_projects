/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:43 by haryu             #+#    #+#             */
/*   Updated: 2022/03/21 22:45:32 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// header
# include "../library/mlx/mlx.h"
# include "../library/libft/libft.h"
# include "../library/gnl/get_next_line.h"
# include "meta_data.h"
# include "map.h"
# include "element.h"

// defines

# define EN_0 "./asset/enemy/enemy_1.xpm"
# define EN_1 "./asset/enemy/enemy_2.xpm"
# define EN_2 "./asset/enemy/enemy_3.xpm"
# define EN_3 "./asset/enemy/enemy_4.xpm"
# define PLAYER_0 "./asset/player/plaer_1.xpm"
# define PLAYER_1 "./asset/player/plaer_2.xpm"
# define PLAYER_2 "./asset/player/plaer_3.xpm"
# define PLAYER_3 "./asset/player/plaer_4.xpm"

typedef struct s_module
{
	t_mlx		game;
	t_intro		intro;
	t_map		map;
	int			map_number;
	int			sys_status;
	t_player	player;
	t_list		coin;
	t_position	starting;
	t_position	exit;
}				t_module;

// game main menu
void	game_main(t_module **init);
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
int		map_put(t_mlx *vars, t_img *img, int x, int y);
int		map_checker(char *map, t_module **init);
int		map_resolution(char *map, t_module **init, unsigned int *x, unsigned int *y);

// element load & image print
int		element_load(t_module *init);
int		player_load(t_module *init);
int		coint_load(t_module *init);

// map error check
int		map_error(int fd, t_rule *rules, unsigned int *width, unsigned int *height);
void	find_target(char *str, t_rule *target);
void	initialize_rules(t_rule *rules);
int		width_check(unsigned int height, unsigned int width, unsigned int current);
int		wall_check(char *str, int height, int width, int *open);

// hook & events
int		key_hook_switch(int kecode, t_module *init);
int		mlx_close(int keycode, t_mlx *vars);
int		press_close(t_mlx *vars);
void	press_move_key(int keycode);
int		status_control(int keycode, t_module *init, int game_status);

// utills
char	*mapnum_out(int map_num);
void	print_current_system(t_module *init);
#endif
