/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:46:55 by haryu             #+#    #+#             */
/*   Updated: 2021/11/16 17:42:14 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *ft_strdup(const char *s1);

int	main(int ac, char **av)
{
	const char	*s1;

	(void)ac;
	s1 = av[1];
	printf("original : ");
	printf("%s", strdup(s1));
	printf("\nre-code : ");
	printf("%s\n", ft_strdup(s1));
	return (0);
}
