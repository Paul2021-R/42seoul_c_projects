/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:46:10 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 16:06:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_x_y_coin(t_module *init, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)init->map.position.y / SIZE)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				element_put(&init->game, init->coin, j * SIZE, i * SIZE);
			j++;
		}
		i++;
	}
	return (0);
}

int	coin_load(t_module *init)
{
	char	**map;

	map = init->map.rule.map_data;
	init->coin = malloc(sizeof(t_img) * 1);
	if (!init->coin)
	{
		printf("<sys>\nCoin malloc is failed\n%s\nError\n", strerror(errno));
		exit(1);
	}
	graphic_init(init, 'C');
	check_x_y_coin(init, map);
	return (0);
}
