/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:27:32 by haryu             #+#    #+#             */
/*   Updated: 2022/02/18 23:33:31 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_error(int fd)
{
	return (1);
	return (0);
}

int map_width_check(int *arr, int height, int width);

int map_wall_check(char *map, int *arr, int height, int width);

int map_rule_check(char *map, int height, int width);
