/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:43 by haryu             #+#    #+#             */
/*   Updated: 2022/03/10 16:03:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//header
# include "../library/mlx/mlx.h"
# include "../library/libft/libft.h"
# include "../library/gnl/get_next_line.h"
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
# define OVER "./asset/menu/gameover.xpm"
# define CLEAR "./asset/menu/gameclear.xpm"
# define LOGO "./asset/menu/logo.xpm"
# define MAIN_1 "./asset/menu/main_1.xpm"
# define MAIN_2 "./asset/menu/main_2.xpm"
# define EN_0 "./asset/enemy/enemy_1.xpm"
# define EN_1 "./asset/enemy/enemy_2.xpm"
# define EN_2 "./asset/enemy/enemy_3.xpm"
# define EN_3 "./asset/enemy/enemy_4.xpm"
# define PLAYER_0 "./asset/player/plaer_1.xpm"
# define PLAYER_1 "./asset/player/plaer_2.xpm"
# define PLAYER_2 "./asset/player/plaer_3.xpm"
# define PLAYER_3 "./asset/player/plaer_4.xpm"

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
	int		x;
	int		y;
	char	**map_data;
}				t_map;

typedef struct s_intro
{
	t_img	*logo;
	t_img	*intro_1;
	t_img	*intro_2;
	t_img	*gameover;
	t_img	*gameclear;
}				t_intro;

typedef struct s_player
{
	t_img	**sprite;
}				t_player;

typedef struct s_enemy
{
	t_img	*sprite_0;
	t_img	*sprite_1;
	t_img	*sprite_2;
	t_img	*sprite_3;
}				t_enemy;

typedef struct s_module
{
	t_mlx		vars;
	t_intro		intro;
	t_map		map;
	int			map_number;
	t_enemy		*enemies;
	t_player	*player;
	int			system;
}				t_module;

typedef struct s_rule
{
	int		starting;
	int		collect;
	int		exit;
}				t_rule;

// game main menu
void	game_main(t_module **init);
int		intro_load(t_mlx *vars, t_intro *data);
int		intro_initialize(t_mlx *vars, t_intro *intro);
int		intro_print(t_mlx *vars, t_intro *intro, int keycode);

// map load & image print
void	game_map(t_module **init, int map_num);
void	map_save(t_map *map, char *line, int y);
int		map_load(t_mlx *vars, t_map *data, char *map_num);
int		map_initialize(t_mlx *vars, t_map *data);
int 	map_print(t_mlx *vars, t_map *map, char *map_num);
int		map_line(char *line, t_mlx *vars, t_map *map);
int		map_put(t_mlx *vars, t_img *img, int x, int y);
int		map_checker(char *map, int *x, int *y);
int		map_resolution(char *map, int *x, int *y);

// elements respawn
void	elements_call(t_module **init);
void	enemy_print(t_mlx *vars, t_enemy *en, int x, int y);
void	enemy_load(t_mlx *vars, t_enemy *enemy, int x, int y);
void	enemy_cal(char **map ,t_mlx *vars, t_enemy *en, int resolution);
void	player_call(t_map *map,t_mlx *vars, t_player *player);

//map error check
int		map_error(int fd, int *width, int *height);
void	find_target(char *str, t_rule *target);
void	initialize_rules(t_rule *rules);
int		width_check(int height, int width, int current);
int		wall_check(char *str, int height, int width, int *open);

// hook & events 
int		key_hook_switch(int kecode, t_module **init);
int		mlx_close(int keycode, t_mlx *vars);
int		press_close(t_mlx *vars);
void	press_move_key(int keycode);

// utills
char	*mapnum_out(int map_num);
void	print_current_system(t_module **init);
#endif
