/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:56:23 by haryu             #+#    #+#             */
/*   Updated: 2021/11/12 23:05:44 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

extern void *ft_memmove(void *dst, const void *src, size_t n);

int main(int ac, char **av)
{
	size_t	i;
	char	*a1;
	char	b[20] = "hihihihihihih";
	char	*a2;

	i = atoi(av[1]);
	(void)ac;
	a1 = av[2];
	a2 = av[3];
	memmove(a1, a2, i);
	printf("%s\n", a1);
	//ft_memcpy(b, a2, i);
	//printf("%s\n", b);
	return (0);
}
