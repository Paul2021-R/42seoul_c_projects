/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_call.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:51:34 by haryu             #+#    #+#             */
/*   Updated: 2022/02/24 17:06:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	elements_call(t_module **init)
{
	(*init)->enemies = malloc(sizeof(t_enemy) * 1);
	enemy_load(&(*init)->vars, (*init)->enemies, 0, 0);
	enemy_cal((*init)->map.map_data, &(*init)->vars, (*init)->enemies, (*init)->map.y);
	return ;
}
// enemy 숫자 맞춰서 호출 해야함
