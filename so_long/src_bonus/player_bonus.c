/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:08:52 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 22:57:56 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/so_long_bonus.h"

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

void	player_malloc(t_player *player)
{
	player->sprite_up = (t_img *)malloc(sizeof(t_img) * 3);
	if (!player->sprite_up)
		malloc_error(strerror(errno));
	player->sprite_down = (t_img *)malloc(sizeof(t_img) * 3);
	if (!player->sprite_down)
		malloc_error(strerror(errno));
	player->sprite_left = (t_img *)malloc(sizeof(t_img) * 3);
	if (!player->sprite_left)
		malloc_error(strerror(errno));
	player->sprite_right = (t_img *)malloc(sizeof(t_img) * 3);
	if (!player->sprite_right)
		malloc_error(strerror(errno));
}

int	player_initialize(t_player *me, t_module *init)
{
	t_img	**frame;

	me->steps = 0;
	if (player_position_init(&me->position, init))
	{
		printf("<sys>\nSetting player is failed!\n");
		exit(1);
	}
	player_malloc(me);
	p_image_load(me->sprite_up, &init->game, UP);
	p_image_load(me->sprite_down, &init->game, DOWN);
	p_image_load(me->sprite_left, &init->game, LEFT);
	p_image_load(me->sprite_right, &init->game, RIGHT);
	return (0);
}

int	player_load(t_module *init)
{
	player_initialize(&init->player, init);
	element_put(&init->game, &init->player.sprite_right[2], \
	init->player.position.x * SIZE, init->player.position.y * SIZE);
	return (0);
}
