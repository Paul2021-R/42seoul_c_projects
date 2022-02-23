/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:17:32 by haryu             #+#    #+#             */
/*   Updated: 2022/02/24 00:25:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*mapnum_out(int map_num)
{
	if (map_num == 18)
		return ("1");
	else if (map_num == 19)
		return ("2");
	else if (map_num == 20)
		return ("3");
	else
		return ("4");
}
