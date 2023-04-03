/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:21:24 by haryu             #+#    #+#             */
/*   Updated: 2022/03/25 16:44:50 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mandatory/so_long.h"

void	check_img_pointer_intro(t_intro *intro)
{
	int	error;

	error = 0;
	if (intro->logo->img == NULL)
		error++;
	if (intro->intro_1->img == NULL)
		error++;
	if (intro->gameclear->img == NULL)
		error++;
	if (intro->gameover->img == NULL)
		error++;
	if (error != 0)
	{
		printf("<sys>\nYour image load is failed.\nTarget : intro\nError\n");
		exit(1);
	}
}

void	check_img_pointer_map(t_map *data)
{
	int	error;

	error = 0;
	if (data->exit->img == NULL)
		error++;
	if (data->pass->img == NULL)
		error++;
	if (data->starting->img == NULL)
		error++;
	if (data->wall->img == NULL)
		error++;
	if (error != 0)
	{
		printf("<sys>\nYour image load is failed.\nTarget : Map\nError\n");
		exit(1);
	}
}
