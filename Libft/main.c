/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:56:23 by haryu             #+#    #+#             */
/*   Updated: 2021/11/12 15:21:36 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

extern char *ft_strnstr(const char *big, const char *little, size_t len);

int main(int ac, char **av)
{
	int	i;

	i = 10;
	printf("origin : %s\n", strnstr(av[1], av[2], i));
	return (0);
}
