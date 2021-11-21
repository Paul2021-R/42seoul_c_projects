/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:55 by haryu             #+#    #+#             */
/*   Updated: 2021/11/21 22:04:24 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	char	*ret;

	(void)ac;
	while (*av[1])
	{
		write(1, av[1]++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
