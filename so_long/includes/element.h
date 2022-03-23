/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:50 by haryu             #+#    #+#             */
/*   Updated: 2022/03/23 14:38:12 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "meta_data.h"

/*Define sprite*/
# define P_UP "./asset/player/pac_open_up.xpm"
# define P_DOWN "./asset/player/pac_open_down.xpm"
# define P_RIGHT "./asset/player/pac_open_right.xpm"
# define P_LEFT "./asset/player/pac_open_left.xpm"

typedef struct s_player
{
	t_img			*sprite;
	t_position		position;
	unsigned int	collected;
	unsigned int	enc_exit;
	unsigned int	steps;
}				t_player;

typedef struct s_enemy
{
	t_img			*sprite;
	t_position		position;
	unsigned int	random;
	unsigned int	enc_player;
}				t_enemy;

typedef struct s_coin
{
	t_img			*sprite;
	unsigned int	enc_player;
	t_position		position;
}				t_coin;

#endif
