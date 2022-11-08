/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:16:58 by haryu             #+#    #+#             */
/*   Updated: 2022/11/06 21:23:49 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mandatory/cub3d.h"

int	check_config(char* config)
{
	return (TRUE);
}

void printError(unsigned int code)
{
	printf("%s\n")
}

int read_map(t_meta_map* meta_data, int fd)
{
	char			*buffer;
	char			*temp;
	int				cnt;
	char			*config;

	buffer = ft_calloc(2, sizeof(char));
	config = ft_calloc(7, sizeof(char));
	if (buffer && config)
	{
		printf("Malloc failed.\n");
		exit(1);
	}
	cnt = read(fd, buffer, 1);
	while (cnt)
	{
		buffer[1] = 0;
		if (buffer[0] == 'N' && config[0] == 0)
		{
			temp = get_next_line(fd);
			if (temp)
				printError(ERR_MAP_PARSSING);
			meta_data->north = ft_strtrim(temp, "NO ");
			free(temp);
			config[0] = 1;
		}
		else if (buffer[0] == 'S' && config[1] == 0)
		{
			temp = get_next_line(fd);
			if (temp)
				printError(ERR_MAP_PARSSING);
			meta_data->south = ft_strtrim(temp, "SO ");
			free(temp);
			config[1] = 1;
		}
		else if (buffer[0] == 'W' && config[2] == 0)
		{
			temp = get_next_line(fd);
			if (temp)
				printError(ERR_MAP_PARSSING);
			meta_data->weast = ft_strtrim(temp, "WE ");
			free(temp);
			config[2] = 1;
		}
		else if (buffer[0] == 'E' && config[3] == 0)
		{
			temp = get_next_line(fd);
			if (temp)
				printError(ERR_MAP_PARSSING);
			meta_data->east = ft_strtrim(temp, "EA ");
			free(temp);
			config[3] = 1;
		}
		else if (buffer[0] == 'F' && config[4] == 0)
		{
			temp = get_next_line(fd);
			if (temp)
				printError(ERR_MAP_PARSSING);
			meta_data->floor = get_RGB(temp, "F");
			free(temp);
			config[4] = 1;
		}
		else if (buffer[0] == 'C' && config[5] == 0)
		{
			temp = get_next_line(fd);
			if (temp)
				printError(ERR_MAP_PARSSING);
			meta_data->ceil = get_RGB(temp, "C");
			free(temp);
			config[5] = 1;
		}
		if (check_config(config) && config[7] == 0)
			get_map(meta_data, fd, config);
		cnt = read(fd, buffer, 1);
	}
	if (check_final_config(config))
		return (FALSE);
	return (TRUE);
}

int	main(int ac, char **av)
{
	int			map;
	t_meta_map	meta_map;

	if (ac != 2)
	{
		printf("Usage: ./cub3D {map}\nError\n");
		exit(1);
	}
	map = open(av[1], O_RDONLY);
	if (map < 0)
	{
		printf("Map has Error: %s\n", strerror(errno));
		exit(1);
	}
	if (read_map(&meta_map, map))
	{
		printf("Map parrsing has error.\n");
		exit(1);
	}
	return (0);
}
