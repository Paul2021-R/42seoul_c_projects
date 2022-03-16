/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:31:01 by haryu             #+#    #+#             */
/*   Updated: 2022/03/17 01:24:01 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int intro_load(t_mlx *game, t_intro *data)
{
	int i;

	if (intro_initialize(game, data))
	{
		printf("error\n");
		exit(1);
	}
	intro_print(game, data, GAME_LOGO);

	return (0);
}

int	intro_malloc(t_intro *intro)
{
	intro->logo = malloc(sizeof(t_img) * 1);
	intro->intro_1 = malloc(sizeof(t_img) * 1);
	intro->intro_2 = malloc(sizeof(t_img) * 1);
	intro->gameover = malloc(sizeof(t_img) * 1);
	intro->gameclear = malloc(sizeof(t_img) * 1);
	if (intro->logo == NULL || intro->intro_1 == NULL \
			|| intro->intro_2 == NULL || intro->gameover == NULL \
			|| intro->gameclear == NULL)
		return (TRUE);
	return (FALSE);
}

int intro_initialize(t_mlx *game, t_intro *intro)
{
	if (intro_malloc(intro))
	{
		printf("error\n");
		exit(1);
	}
	intro->logo->img = mlx_xpm_file_to_image(game->mlx, LOGO, &intro->logo->width, &intro->logo->height);
	intro->intro_1->img = mlx_xpm_file_to_image(game->mlx, MAIN_1, &intro->intro_1->width, &intro->intro_1->height);
	intro->intro_2->img = mlx_xpm_file_to_image(game->mlx, MAIN_2, &intro->intro_2->width, &intro->intro_2->height);
	intro->gameover->img = mlx_xpm_file_to_image(game->mlx, OVER, &intro->gameover->width, &intro->gameover->height);
	intro->gameclear->img = mlx_xpm_file_to_image(game->mlx, CLEAR, &intro->gameclear->width, &intro->gameclear->height);
	return (0);
}

int	intro_print(t_mlx *game, t_intro *intro, int game_status)
{
	void	*current;

	if (game_status == GAME_LOGO)
		current = intro->logo->img;
	else if (game_status == GAME_MAIN_1)
		current = intro->intro_1->img;
	else if (game_status == GAME_MAIN_2)
		current = intro->intro_2->img;
	else if (game_status == GAME_CLEAR)
		current = intro->gameclear->img;
	else if (game_status == GAME_OVER)
		current = intro->gameover->img;
	mlx_put_image_to_window(game->mlx, game->mlx_win, current, 0, 0);
	printf("Current game status is [%d].\n", game_status);
	return (0);
}
