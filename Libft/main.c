/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:55 by haryu             #+#    #+#             */
/*   Updated: 2021/11/19 18:48:53 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	char	*s;
	char	set;
	char	**ret;
	int	i;

	(void)ac;
	s = av[1];
	set = av[2][0];
	printf("re-code : \n");
	ret = ft_split(s, set);
	i = 0;
	while (ret[i])
	{
		printf("%s\n", ret[i]);
		i++;
	}
	return (0);
}
