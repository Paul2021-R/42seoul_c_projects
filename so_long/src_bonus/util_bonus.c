/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:47:21 by haryu             #+#    #+#             */
/*   Updated: 2022/03/24 16:47:29 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/so_long_bonus.h"

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
	printf("----------------------------------\n");
	printf("< SO_LONG proejct system checker >\n");
	printf("1. Current system status : %d\n", init->sys_status);
	printf("2. Map number : %d\n", init->map_number);
	printf("3. Map size X : %d  Y : %d\n", \
	init->map.position.x, init->map.position.y);
	printf("4. Map data : \n");
	while (init->sys_status == GAME_PLAYING && \
	i < (int)init->map.position.y / SIZE)
		printf("    %s", init->map.rule.map_data[i++]);
	printf("5. Left coin  : %d\n", init->map.rule.collect);
	printf("6. Player Position X : %d Y : %d\n", \
	init->player.position.x, init->player.position.y);
	printf("7. player STEPs : %d\n", init->player.steps);
	printf("----------------------------------\n");
}

char	*print_directory(int arrow)
{
	char	*dir;

	if (arrow == UP)
		dir = "_up.xpm";
	else if (arrow == DOWN)
		dir = "_down.xpm";
	else if (arrow == LEFT)
		dir = "_left.xpm";
	else
		dir = "_right.xpm";
	return (dir);
}

void	*frame_init(int *value, int arrow)
{
	int	i;

	i = -1;
	while (++i < 3 && arrow == 0)
		value[i] = 0;
	if (arrow == UP || arrow == LEFT)
	{
		value[0] = 22;
		value[1] = 10;
		value[2] = 0;
	}
	if (arrow == DOWN || arrow == RIGHT)
	{
		value[0] = -22;
		value[1] = -10;
		value[2] = 0;
	}
}
