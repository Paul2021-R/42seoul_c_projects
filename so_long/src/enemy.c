/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:18:16 by haryu             #+#    #+#             */
/*   Updated: 2022/03/11 18:17:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	enemy_print(t_mlx *vars, t_enemy *en, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, en->sprite_0->img, x, y);
	return ;
}

void	enemy_load(t_mlx *vars, t_enemy *enemy, int x, int y)
{
	enemy->sprite_0 = malloc(sizeof(t_img) * 1);
	enemy->sprite_1 = malloc(sizeof(t_img) * 1);
	enemy->sprite_2 = malloc(sizeof(t_img) * 1);
	enemy->sprite_3 = malloc(sizeof(t_img) * 1);
	enemy->sprite_0->img = mlx_xpm_file_to_image(vars->mlx, EN_0, &enemy->sprite_0->width, &enemy->sprite_0->height);
	enemy->sprite_1->img = mlx_xpm_file_to_image(vars->mlx, EN_1, &enemy->sprite_1->width, &enemy->sprite_1->height);
	enemy->sprite_2->img = mlx_xpm_file_to_image(vars->mlx, EN_2, &enemy->sprite_2->width, &enemy->sprite_2->height);
	enemy->sprite_3->img = mlx_xpm_file_to_image(vars->mlx, EN_3, &enemy->sprite_3->width, &enemy->sprite_3->height);
	enemy_print(vars, enemy, x, y);
	return ;
}

int	how_many(char **map, char target, int height)
{
	int		ret;
	int		x;
	int		j;

	j = 0;
	x = 0;
	ret = 0;
	while(j < height)
	{
		x = 0;
		while(map[j][x])
		{
			if (map[j][x] == target)
				ret++;
			x++;
		}
		j++;
	}
	return (ret);
}

void	what_coordination(char **map, char target, int *cor, int height)
{
	int	x;
	int	width;
	int	y;

	x = 0;
	y = 0;
	width = ft_strlen(map[0]);
	while (y < height)
	{
		y++;	
	}	
}
void	enemy_cal(char **map, t_mlx *vars, t_enemy *en, int resolution)
{
	int	en_count;
	int height;
	int	coordination[2];

	height = resolution / 50;
	en_count = how_many(map, 'R', height);
	en = malloc(sizeof(t_enemy) * en_count);
	if (!en)
	{
		printf("error!\n");
		exit (0);
	}
	while (en_count > 0)
	{
		what_coordination(map, 'R', &(*coordination), height);
		enemy_load(vars, en, coordination[0], coordination[1]);
		en_count--;
	}
	
}

