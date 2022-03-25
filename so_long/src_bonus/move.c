/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:40:38 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 16:17:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_move_ok(char **map, unsigned int *x, unsigned int *y, int arrow)
{
	int	new_x;
	int	new_y;

	new_x = *x;
	new_y = *y;
	if (arrow == UP)
		new_y--;
	else if (arrow == DOWN)
		new_y++;
	else if (arrow == LEFT)
		new_x--;
	else
		new_x++;
	if (map[new_y][new_x] == 'C' || map[new_y][new_x] == '0' \
	|| map[new_y][new_x] == 'E' || map[new_y][new_x] == 'P')
	{
		*x = new_x;
		*y = new_y;
		return (1);
	}
	return (0);
}

void	map_switch_put(t_module *init, t_map *map, t_position old)
{
	int	x;
	int	y;

	x = old.x;
	y = old.y;
	if (map->rule.map_data[y][x] == '0' || map->rule.map_data[y][x] == 'C')
		mlx_put_image_to_window(init->game.mlx, \
		init->game.mlx_win, map->pass->img, x * SIZE, y * SIZE);
	else if (map->rule.map_data[y][x] == 'P' || map->rule.map_data[y][x] == 'E')
		mlx_put_image_to_window(init->game.mlx, \
		init->game.mlx_win, map->exit->img, x * SIZE, y * SIZE);
	return ;
}

void	player_switch_put(t_module *init)
{
	element_put(&init->game, init->player.sprite, \
	init->player.position.x * SIZE, init->player.position.y * SIZE);
}

void	render_every_thing(t_module *init, t_position old)
{
	unsigned int	x;
	unsigned int	y;

	x = init->player.position.x;
	y = init->player.position.y;
	map_switch_put(init, &init->map, old);
	player_switch_put(init);
	printf("<sys> Your Step : %d\n", init->player.steps + 1);
	if (init->map.rule.map_data[y][x] == 'C')
	{
		init->map.rule.collect--;
		init->map.rule.map_data[y][x] = '0';
	}
	if (init->map.rule.map_data[y][x] == 'E' && init->map.rule.collect <= 0)
	{
		printf("<sys> You Win!\n");
		print_current_system(init);
		mlx_destroy_window(init->game.mlx, init->game.mlx_win);
		game_intro(init, GAME_CLEAR);
	}
}

int	move(int arrow, t_module *init)
{
	t_position		old;
	t_position		*new;
	char			map[1];

	old = init->player.position;
	new = &init->player.position;
	map[0] += init->map_number;
	if (check_move_ok(init->map.rule.map_data, &new->x, &new->y, arrow))
	{
		render_every_thing(init, old);
		init->player.steps += 1;
		if (init->player.steps == 254)
		{
			printf("<sys> Your steps is overwhelming upto 255.\n");
			printf("<sys> You lose (ㅠ ㅠ)\n");
			print_current_system(init);
			mlx_destroy_window(init->game.mlx, init->game.mlx_win);
			game_intro(init, GAME_OVER);
		}
		return (0);
	}
	printf("<sys> you can't go there\n");
	return (0);
}
