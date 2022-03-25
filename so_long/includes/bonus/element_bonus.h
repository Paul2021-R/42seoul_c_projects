/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:50 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 22:21:56 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_BONUS_H
# define ELEMENT_BONUS_H

# include "meta_data_bonus.h"

# define P_SEMI "./asset/player/pac_semi"
# define P_OPEN "./asset/player/pac_open"

# define P_DEFAULT "./asset/player/pac_closed.xpm"

# define COIN "./asset/map/collect_xpm.xpm"

typedef struct s_player
{
	t_img			*sprite_up;
	t_img			*sprite_down;
	t_img			*sprite_right;
	t_img			*sprite_left;
	t_position		position;
	unsigned int	steps;
}				t_player;

typedef struct s_enemy
{
	t_img			*sprite;
	t_position		position;
	unsigned int	random;
}				t_enemy;

#endif
