/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:50 by haryu             #+#    #+#             */
/*   Updated: 2022/03/21 22:34:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "meta_data.h"

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
