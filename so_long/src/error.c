/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:27:32 by haryu             #+#    #+#             */
/*   Updated: 2022/03/21 22:49:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_error(int fd, t_rule *rules, unsigned int *width, unsigned int *height)
{
	char	*check;
	int		wall_open;

	wall_open = 0;
	initialize_rules(rules);
	while (1)
	{
		check = get_next_line(fd);
		if (!check)
			break ;
		find_target(check, rules);
		if (*height == 1)
			*width = (unsigned int)ft_strlen(check);
		if (width_check(*height, *width, (unsigned int)ft_strlen(check)))
			return (TRUE);
		if (wall_check(check, *height, *width, &wall_open))
			return (TRUE);
		free (check);
		(*height)++;
	}
	if (rules->starting < 1 || rules->exit < 1 || wall_open != 0)
		return (TRUE);
	return (0);
}

int	wall_check(char *str, int height, int width, int *open)
{
	int	i;

	i = 0;
	*open = 0;
	while (str[i])
	{
		if (height == 1 && i < width - 1 && str[i] != '1')
			return (TRUE);
		else if (height > 1 && (str[0] != '1' || str[width - 2] != '1'))
			return (TRUE);
		if (str[i] == '1' || str[i] == '\n')
			(*open)++;
		i++;
	}
	if (*open != width)
		*open = 1;
	else
		*open = 0;
	return (0);
}

int	width_check(unsigned int height, unsigned int width, unsigned int current)
{
	if (height > 1)
		if (width != current)
			return (TRUE);
	return (0);
}

void	find_target(char *str, t_rule *target)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == 'C')
			target->collect += 1;
		else if (*str == 'E')
			target->exit += 1;
		else if (*str == 'P')
			target->starting += 1;
		str++;
	}
}

void	initialize_rules(t_rule *rules)
{
	rules->starting = 0;
	rules->collect = 0;
	rules->exit = 0;
	rules->map_data = NULL;
}
