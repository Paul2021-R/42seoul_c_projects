/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:48:50 by haryu             #+#    #+#             */
/*   Updated: 2022/03/16 15:40:27 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

typedef struct s_player
{
	t_img			*sprite;
	t_position		position;
	unsigned int	collected : 2;
	unsigned int	enc_exit : 1;
	unsigned int	steps : 1;
}				t_player;

typedef struct s_enemy;
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
