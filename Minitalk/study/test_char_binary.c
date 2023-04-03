/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_char_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:25:00 by haryu             #+#    #+#             */
/*   Updated: 2022/03/30 23:35:57 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	binary_print_out(char c)
{
	int	i;
	int	signal;

	i = 8;
	while (--i >= 0)
	{
		signal = c >> i & 1;
		printf("%d", signal);
	}
}

int main(int ac, char **av)
{
	int i;
	int c;

	i = 0;
	while (i < strlen(av[1]))
	{
		binary_print_out(av[1][i]);
		printf(" ");
		i++;
	}
	printf("\n");
	return (0);
}