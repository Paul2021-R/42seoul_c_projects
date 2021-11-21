/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:55 by haryu             #+#    #+#             */
/*   Updated: 2021/11/22 00:26:23 by haryu            ###   ########.fr       */
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
	int		i;

	(void)ac;
	s = (char *)av[1];
	set = av[2][0];
	printf("re-code : \n");
	ret = ft_split(s, set);
	i = 0;
	while (ret[i])
	{
		printf("%s\n", ret[i]);
		i++;
	}
	i = 0;
	/*while (ret[i])
	{
		free(ret[i]);
		i++;
	}*/
	//free (ret);
	return (0);
}
