/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:32:27 by haryu             #+#    #+#             */
/*   Updated: 2022/01/02 19:12:10 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int main(void)
{
	int a = 100;
	long int b = -2147483648;
	unsigned int c = 2147483659;
	char *d = "test. hello world";
	int	e = 20;
	int	*ptr = &e;

	int ret = ft_printf("자작한 것 : %d %d %u %s %x %X %p",a , b, c, d, e, e, ptr);
	printf ("\nreturn : %d\n", ret);
	printf("%p\n", ptr);
	return (0);
}
