/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:55:16 by haryu             #+#    #+#             */
/*   Updated: 2022/03/16 20:57:26 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef META_DATA_H
# define META_DATA_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>

/*
 * graphic data
 */

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

/*
 * module base
 */

typedef struct s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_leng;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_mlx 
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx;

typedef struct s_position
{
	unsigned int	x;
	unsigned int	y;
}			t_position;

typedef struct s_rule
{
	unsigned int	starting : 1;
	unsigned int	collect : 2;
	unsigned int	exit : 1;
	char			**map_data;
}			t_rule;


/*
 * Game meta Data
 */

# define TURE 1
# define FALSE 0

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ENTER 36
# define KEY_ESC 53
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_P 35

/* Sprite */
# define SIZE 50

# define BYTE_MAX 255

/* Game Scene Status */
# define GAME_LOGO 0
# define GAME_MAIN_1 1
# define GAME_MAIN_2 2
# define GAME_PLAYING 3
# define GAME_CLEAR 4
# define GAME_OVER 5

#endif
