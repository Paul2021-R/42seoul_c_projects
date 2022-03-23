/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:08:52 by haryu             #+#    #+#             */
/*   Updated: 2022/03/24 00:48:40 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_x_y(char **map, unsigned int *x, unsigned int *y, char checker)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' || !map[i][j])
		{
			if (map[i][j] == checker)
			{
				*x = j;
				*y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	player_position_init(t_position *position, t_module *init)
{
	char	**map;

	map = init->map.rule.map_data;
	if (check_x_y(map, &position->x, &position->y, 'P'))
	{
		return (1);
	}
	return (0);
}

int	player_initialize(t_player *me, t_module *init)
{
	me->collected = 0;
	me->enc_exit = FALSE;
	me->steps = 0;
	if (player_position_init(&me->position, init))
	{
		printf("<sys> Setting player is failed!\n");
		exit(1);
	}
	me->sprite = malloc(sizeof(t_img) * 1);
	if (!me->sprite)
	{
		printf("<sys> Player malloc is failed\n");
		exit(1);
	}
	p_image_load(me->sprite, &init->game);
	return (0);
}

int	player_load(t_module *init)
{
	player_initialize(&init->player, init);
	element_put(&init->game, init->player.sprite, init->player.position.x * SIZE, init->player.position.y * SIZE);
	return (0);
}