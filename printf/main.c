/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:32:27 by haryu             #+#    #+#             */
/*   Updated: 2022/01/16 14:49:23 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int a = 100;
	long int b = -2147483648;
	unsigned int c = 21474;
	char *d = "test. hello world";
	int	e = 20;
	int	*ptr = &e;

	int ret = ft_printf("self_printf : %c %d %d %u %s %x %X %p 33%%", 'k' ,a , b, c, d, e, e, ptr);

	printf ("\nreturn : %d\n", ret);
	return (0);
}
