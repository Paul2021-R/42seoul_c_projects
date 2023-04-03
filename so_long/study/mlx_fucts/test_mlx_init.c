/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:51:17 by haryu             #+#    #+#             */
/*   Updated: 2022/02/10 21:21:21 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	printf("value of mlx pointer : %p\n", mlx);
	mlx_win = mlx_new_window(mlx, 1024, 768, "hello world!");
	mlx_loop(mlx);

}
