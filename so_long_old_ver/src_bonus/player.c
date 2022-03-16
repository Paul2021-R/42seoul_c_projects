/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:58:34 by haryu             #+#    #+#             */
/*   Updated: 2022/03/11 17:30:54 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_player(t_mlx *vars, t_img *sprite, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, sprite[0].img, x, y);
	return ;
}

void	player_load(t_mlx *vars, t_player *player, int x, int y)
{
	int i;

	i = 0;
	player = malloc(sizeof(t_player) * 1);
	player->sprite = malloc(sizeof(t_img *) * 4);
	while (i < 4)
	{
		printf("%d\n", i);
		player->sprite[i] = malloc(sizeof(t_img) * 1);
		if (i == 0)
		{
			player->sprite[i][0].img = mlx_xpm_file_to_image(vars->mlx, PLAYER_0, &player->sprite[i][0].width, &player->sprite[i][0].height);
			printf("\n0번 할당 : %p\n",&player->sprite[i]->img);
		}
		if (i == 1)
		{
			player->sprite[i][0].img = mlx_xpm_file_to_image(vars->mlx, PLAYER_1, &player->sprite[i][0].width, &player->sprite[i][0].height);
			printf("\n1번 할당 : %p\n",&player->sprite[i]->img);
		}
		if (i == 2)
		{
			player->sprite[i][0].img = mlx_xpm_file_to_image(vars->mlx, PLAYER_2, &player->sprite[i][0].width, &player->sprite[i][0].height);
			printf("\n2번 할당 : %p\n",&player->sprite[i]->img);
		}
		if (i == 3)
		{
			player->sprite[i][0].img = mlx_xpm_file_to_image(vars->mlx, PLAYER_3, &player->sprite[i][0].width, &player->sprite[i][0].height);
			printf("\n3번 할당 : %p\n",&player->sprite[i]->img);
		}

		i++;
	}
}

int	what_coordinates(char **map, int *x, int *y, int limit)
{
	int		i;
	int  	j;
	char	*row;

	i = 0;
	j = 0;
	limit /= 50;
	while (i < limit)
	{
		row = ft_strrchr(map[i], 'P');
		if (row != NULL)
		{
			*x = (int)(&row[0] - &map[i][0]);
			j += 1;
			if (j == 2)
				break ;
			*y = i;
		}
		i++;
	}
	*x *= 50;
	*y *= 50;
	if (j != 1)
		return (1);
	else 
		return (0);
}

void	player_call(t_map *map, t_mlx *vars, t_player *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (what_coordinates((*map).map_data, &x, &y, (*map).y))
	{
		printf("map data가 잘못 되어 있습니다.");
		exit(1);
	}
	player_load(vars, player, x, y);
	printf("x = %d y = %d\n", x, y);
	printf("%p\n", &player->sprite[0]);
	print_player(vars, player->sprite[0], x, y);
	
}
