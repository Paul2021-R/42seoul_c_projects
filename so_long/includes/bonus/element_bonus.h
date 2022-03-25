/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:50 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 16:47:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_BONUS_H
# define ELEMENT_BONU_H

# include "meta_data.h"

/*Define sprite*/
# define P_UP "./asset/player/pac_open_up.xpm"
# define P_DOWN "./asset/player/pac_open_down.xpm"
# define P_RIGHT "./asset/player/pac_open_right.xpm"
# define P_LEFT "./asset/player/pac_open_left.xpm"
# define COIN "./asset/map/collect_xpm.xpm"

typedef struct s_player
{
	t_img			*sprite;
	t_position		position;
	unsigned int	steps;
}				t_player;

typedef struct s_enemy
{
	t_img			*sprite;
	t_position		position;
	unsigned int	random;
	unsigned int	enc_player;
}				t_enemy;

#endif
