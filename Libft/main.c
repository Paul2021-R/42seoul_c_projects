/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:56:23 by haryu             #+#    #+#             */
/*   Updated: 2021/11/11 11:37:35 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

extern int	ft_toupper(int c);

int main(int ac, char **av)
{
	int	len;

	len = strlen(av[1]);
	for (int i = 0; i < len ; i++)
		printf("%c", (char)(toupper(av[1][i])));
	printf("\n");
	for (size_t i =0 ; i < len ; i++)
		printf("%c", (char)(tolower(av[1][i])));
	printf("\n");
	return (0);
}
