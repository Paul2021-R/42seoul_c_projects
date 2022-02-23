/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:18:16 by haryu             #+#    #+#             */
/*   Updated: 2022/02/23 22:01:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_print(t_mlx *vars, t_enemy *en)
{
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, en->sprite_0->img, 0, 0);
	return ;
}

void	enemy_load(t_mlx *vars, t_enemy *enemy)
{
	enemy->sprite_0 = malloc(sizeof(t_img) * 1);
	enemy->sprite_1 = malloc(sizeof(t_img) * 1);
	enemy->sprite_2 = malloc(sizeof(t_img) * 1);
	enemy->sprite_3 = malloc(sizeof(t_img) * 1);
	enemy->sprite_0->img = mlx_xpm_file_to_image(vars->mlx, EN_0, &enemy->sprite_0->width, &enemy->sprite_0->height);
	enemy->sprite_1->img = mlx_xpm_file_to_image(vars->mlx, EN_1, &enemy->sprite_1->width, &enemy->sprite_1->height);
	enemy->sprite_2->img = mlx_xpm_file_to_image(vars->mlx, EN_2, &enemy->sprite_2->width, &enemy->sprite_2->height);
	enemy->sprite_3->img = mlx_xpm_file_to_image(vars->mlx, EN_3, &enemy->sprite_3->width, &enemy->sprite_3->height);
	enemy_print(vars, enemy);
	return ;
}
/*
int main(void)
{
	t_module	*init;
	
	init = malloc(sizeof(t_module) * 1);
	init->vars.mlx = mlx_init();
	init->vars.mlx_win = mlx_new_window(init->vars.mlx, 300, 300, "animation test");
	mlx_loop(init->vars.mlx);
}*/
