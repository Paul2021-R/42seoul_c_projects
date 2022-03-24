/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:45:24 by haryu             #+#    #+#             */
/*   Updated: 2022/03/24 20:41:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_checker(char *map, t_module **init)
{
	unsigned int	*x;
	unsigned int	*y;
	char			*map_dir;

	if (map[0] == '1')
		map_dir = MAP_DIR_1;
	else if (map[0] == '2')
		map_dir = MAP_DIR_2;
	else if (map[0] == '3')
		map_dir = MAP_DIR_3;
	else if (map[0] == '4')
		map_dir = MAP_DIR_4;
	map_resolution(map_dir, init, \
	&(*init)->map.position.x, &(*init)->map.position.y);
	return (0);
}

int	map_resolution(char *map, t_module **init, unsigned int *x, unsigned int *y)
{
	int		fd;
	int		width;
	int		height;
	t_rule	*rules;

	*x = 0;
	*y = 1;
	rules = &(*init)->map.rule;
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		printf("<sys>\nMap file open is failed.\n");
		exit(1);
	}
	if (map_error(fd, rules, x, y))
		error_noti(init);
	*x = SIZE * (*x - 1);
	*y = SIZE * (*y - 1);
	close(fd);
	if (*x > MAX_WIDTH || *y > MAX_HEIGHT)
	{
		printf("<sys>\nThe resolution of a current map file is too big.\n");
		exit (1);
	}
	return (0);
}

void	error_noti(t_module **init)
{
	printf("<sys>\n");
	if ((*init)->map.rule.collect < 1)
		printf("Your map has at least one coin.\n");
	if ((*init)->map.rule.starting < 1)
		printf("Your map has at least one starting point.\n");
	if ((*init)->map.rule.exit < 1)
		printf("Your map has at least one exit point.\n");
	printf("Error\n");
	exit(1);
}
