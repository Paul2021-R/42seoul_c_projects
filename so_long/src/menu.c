/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:31:01 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 16:12:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	intro_load(t_module *init)
{
	if (intro_initialize(&(*init).game, &(*init).intro))
	{
		printf("Error\n");
		exit(1);
	}
	intro_print(&(*init).game, &(*init).intro, GAME_LOGO);
	(*init).map_number = 0;
	(*init).sys_status = GAME_LOGO;
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

int	intro_initialize(t_mlx *game, t_intro *intro)
{
	if (intro_malloc(intro))
	{
		printf("<sys>\nMain load is failed\n[%s]\nError\n", strerror(errno));
		exit(1);
	}
	intro->logo->img = mlx_xpm_file_to_image(game->mlx, \
	LOGO, &intro->logo->width, &intro->logo->height);
	intro->intro_1->img = mlx_xpm_file_to_image(game->mlx, \
	MAIN_1, &intro->intro_1->width, &intro->intro_1->height);
	intro->intro_2->img = mlx_xpm_file_to_image(game->mlx, \
	MAIN_2, &intro->intro_2->width, &intro->intro_2->height);
	intro->gameover->img = mlx_xpm_file_to_image(game->mlx, \
	OVER, &intro->gameover->width, &intro->gameover->height);
	intro->gameclear->img = mlx_xpm_file_to_image(game->mlx, \
	CLEAR, &intro->gameclear->width, &intro->gameclear->height);
	check_img_pointer_intro(intro);
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
	else
		current = intro->gameover->img;
	mlx_put_image_to_window(game->mlx, game->mlx_win, current, 0, 0);
	printf("<sys>\nCurrent game status is [%d].\n", game_status);
	return (0);
}
