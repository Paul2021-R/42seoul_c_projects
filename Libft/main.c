/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:55 by haryu             #+#    #+#             */
/*   Updated: 2021/11/18 18:56:51 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	const char		*s1;
	char			**ret;
	int				i;

	(void)ac;
	s1 = av[1];
	printf("re-code : ");
	ret = ft_split(s1, av[2][0]);
	i = 0;
	while (ret[i])
	{
		printf("%s\n", ret[i]);
		i++;
	}
	return (0);
}
