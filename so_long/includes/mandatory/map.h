/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:33:11 by haryu             #+#    #+#             */
/*   Updated: 2022/03/24 20:32:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "meta_data.h"

typedef struct s_map
{
	t_img		*pass;
	t_img		*wall;
	t_img		*exit;
	t_img		*starting;
	t_position	position;
	t_rule		rule;
}			t_map;

typedef struct s_intro
{
	t_img	*logo;
	t_img	*intro_1;
	t_img	*intro_2;
	t_img	*gameover;
	t_img	*gameclear;
}			t_intro;

# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

#endif
