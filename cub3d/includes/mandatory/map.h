/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:03:59 by haryu             #+#    #+#             */
/*   Updated: 2022/11/06 01:32:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../library/libft/libft.h"
# include "../../library/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <math.h>

# define RESOLUTION_X 1921
# define RESOLUTION_Y 1081

typedef struct s_meta_map
{
	char			*north;
	char			*south;
	char			*weast;
	char			*east;
	char			**meta_map;
	unsigned int	floor;
	unsigned int	ceil;
}				t_meta_map;

#endif