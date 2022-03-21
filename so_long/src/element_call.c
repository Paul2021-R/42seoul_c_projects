/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_call.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:51:34 by haryu             #+#    #+#             */
/*   Updated: 2022/03/21 22:45:47 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	elements_call(t_module *init)
{
	player_load(init);
	coin_load(init);
	return (0);
}
// enemy 숫자 맞춰서 호출 해야함
