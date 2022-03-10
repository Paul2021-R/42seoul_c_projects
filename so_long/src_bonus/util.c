/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:17:32 by haryu             #+#    #+#             */
/*   Updated: 2022/03/10 16:19:39 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

void	print_current_system(t_module **init)
{
	int	i;

	i = 0;
	printf("\n<so_long proejct system check>\n");
	printf("1. system current : %d\n", (*init)->system);
	printf("2. map number : %d\n",(*init)->map_number);
	printf("3. map size X : %d  Y : %d\n", (*init)->map.x, (*init)->map.y);
	printf("4. map data : \n");
	while (i < (*init)->map.y / 50)
		printf("   %s", (*init)->map.map_data[i++]);
}
