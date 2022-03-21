/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:17:32 by haryu             #+#    #+#             */
/*   Updated: 2022/03/21 19:46:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*mapnum_out(int map_num)
{
	if (map_num == KEY_1)
		return ("1");
	else if (map_num == KEY_2)
		return ("2");
	else if (map_num == KEY_3)
		return ("3");
	else
		return ("4");
}

void	print_current_system(t_module *init)
{
	int	i;

	i = 0;
	printf("\n<so_long proejct system check>\n");
	printf("1. system current : %d\n", init->sys_status);
	printf("2. map number : %d\n", init->map_number);
	printf("3. map size X : %d  Y : %d\n", init->map.position.x, init->map.position.y);
	printf("4. map data : \n");
	while (init->sys_status == GAME_PLAYING && i < init->map.position.y / SIZE)
		printf("   %s", init->map.rule.map_data[i++]);
}
